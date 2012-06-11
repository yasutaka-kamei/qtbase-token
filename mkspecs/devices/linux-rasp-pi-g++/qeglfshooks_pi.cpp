begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the qmake spec of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qeglfshooks.h"
end_include
begin_include
include|#
directive|include
file|"qeglfscursor.h"
end_include
begin_include
include|#
directive|include
file|<QtDebug>
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
file|<bcm_host.h>
end_include
begin_if
if|#
directive|if
literal|0
end_if
begin_comment
comment|//fb size query
end_comment
begin_include
include|#
directive|include
file|<stdio.h>
end_include
begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include
begin_include
include|#
directive|include
file|<sys/types.h>
end_include
begin_include
include|#
directive|include
file|<sys/stat.h>
end_include
begin_include
include|#
directive|include
file|<fcntl.h>
end_include
begin_include
include|#
directive|include
file|<linux/fb.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|dispman_display
specifier|static
name|DISPMANX_DISPLAY_HANDLE_T
name|dispman_display
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|createDispmanxLayer
specifier|static
name|EGLNativeWindowType
name|createDispmanxLayer
parameter_list|(
specifier|const
name|QPoint
modifier|&
name|pos
parameter_list|,
specifier|const
name|QSize
modifier|&
name|size
parameter_list|,
name|int
name|z
parameter_list|,
name|DISPMANX_FLAGS_ALPHA_T
name|flags
parameter_list|)
block|{
name|VC_RECT_T
name|dst_rect
decl_stmt|;
name|dst_rect
operator|.
name|x
operator|=
name|pos
operator|.
name|x
argument_list|()
expr_stmt|;
name|dst_rect
operator|.
name|y
operator|=
name|pos
operator|.
name|y
argument_list|()
expr_stmt|;
name|dst_rect
operator|.
name|width
operator|=
name|size
operator|.
name|width
argument_list|()
expr_stmt|;
name|dst_rect
operator|.
name|height
operator|=
name|size
operator|.
name|height
argument_list|()
expr_stmt|;
name|VC_RECT_T
name|src_rect
decl_stmt|;
name|src_rect
operator|.
name|x
operator|=
literal|0
expr_stmt|;
name|src_rect
operator|.
name|y
operator|=
literal|0
expr_stmt|;
name|src_rect
operator|.
name|width
operator|=
name|size
operator|.
name|width
argument_list|()
operator|<<
literal|16
expr_stmt|;
name|src_rect
operator|.
name|height
operator|=
name|size
operator|.
name|height
argument_list|()
operator|<<
literal|16
expr_stmt|;
name|DISPMANX_UPDATE_HANDLE_T
name|dispman_update
init|=
name|vc_dispmanx_update_start
argument_list|(
literal|0
argument_list|)
decl_stmt|;
name|VC_DISPMANX_ALPHA_T
name|alpha
decl_stmt|;
name|alpha
operator|.
name|flags
operator|=
name|flags
expr_stmt|;
name|alpha
operator|.
name|opacity
operator|=
literal|0xFF
expr_stmt|;
name|alpha
operator|.
name|mask
operator|=
literal|0
expr_stmt|;
name|DISPMANX_ELEMENT_HANDLE_T
name|dispman_element
init|=
name|vc_dispmanx_element_add
argument_list|(
name|dispman_update
argument_list|,
name|dispman_display
argument_list|,
name|z
argument_list|,
operator|&
name|dst_rect
argument_list|,
literal|0
argument_list|,
operator|&
name|src_rect
argument_list|,
name|DISPMANX_PROTECTION_NONE
argument_list|,
operator|&
name|alpha
argument_list|,
operator|(
name|DISPMANX_CLAMP_T
operator|*
operator|)
name|NULL
argument_list|,
operator|(
name|DISPMANX_TRANSFORM_T
operator|)
literal|0
argument_list|)
decl_stmt|;
name|vc_dispmanx_update_submit_sync
argument_list|(
name|dispman_update
argument_list|)
expr_stmt|;
name|EGL_DISPMANX_WINDOW_T
modifier|*
name|eglWindow
init|=
operator|new
name|EGL_DISPMANX_WINDOW_T
decl_stmt|;
name|eglWindow
operator|->
name|element
operator|=
name|dispman_element
expr_stmt|;
name|eglWindow
operator|->
name|width
operator|=
name|size
operator|.
name|width
argument_list|()
expr_stmt|;
name|eglWindow
operator|->
name|height
operator|=
name|size
operator|.
name|height
argument_list|()
expr_stmt|;
return|return
name|eglWindow
return|;
block|}
end_function
begin_comment
comment|// this function is not part of debian squeeze headers
end_comment
begin_extern
extern|extern
literal|"C"
name|int
name|VCHPOST_
name|vc_dispmanx_element_change_attributes
parameter_list|(
name|DISPMANX_UPDATE_HANDLE_T
name|update
parameter_list|,
name|DISPMANX_ELEMENT_HANDLE_T
name|element
parameter_list|,
name|uint32_t
name|change_flags
parameter_list|,
name|int32_t
name|layer
parameter_list|,
name|uint8_t
name|opacity
parameter_list|,
specifier|const
name|VC_RECT_T
modifier|*
name|dest_rect
parameter_list|,
specifier|const
name|VC_RECT_T
modifier|*
name|src_rect
parameter_list|,
name|DISPMANX_RESOURCE_HANDLE_T
name|mask
parameter_list|,
name|VC_IMAGE_TRANSFORM_T
name|transform
parameter_list|)
function_decl|;
end_extern
begin_comment
comment|// these constants are not in any headers (yet)
end_comment
begin_define
DECL|macro|ELEMENT_CHANGE_LAYER
define|#
directive|define
name|ELEMENT_CHANGE_LAYER
value|(1<<0)
end_define
begin_define
DECL|macro|ELEMENT_CHANGE_OPACITY
define|#
directive|define
name|ELEMENT_CHANGE_OPACITY
value|(1<<1)
end_define
begin_define
DECL|macro|ELEMENT_CHANGE_DEST_RECT
define|#
directive|define
name|ELEMENT_CHANGE_DEST_RECT
value|(1<<2)
end_define
begin_define
DECL|macro|ELEMENT_CHANGE_SRC_RECT
define|#
directive|define
name|ELEMENT_CHANGE_SRC_RECT
value|(1<<3)
end_define
begin_define
DECL|macro|ELEMENT_CHANGE_MASK_RESOURCE
define|#
directive|define
name|ELEMENT_CHANGE_MASK_RESOURCE
value|(1<<4)
end_define
begin_define
DECL|macro|ELEMENT_CHANGE_TRANSFORM
define|#
directive|define
name|ELEMENT_CHANGE_TRANSFORM
value|(1<<5)
end_define
begin_function
DECL|function|moveDispmanxLayer
specifier|static
name|void
name|moveDispmanxLayer
parameter_list|(
name|EGLNativeWindowType
name|window
parameter_list|,
specifier|const
name|QPoint
modifier|&
name|pos
parameter_list|)
block|{
name|EGL_DISPMANX_WINDOW_T
modifier|*
name|eglWindow
init|=
cast|static_cast
argument_list|<
name|EGL_DISPMANX_WINDOW_T
operator|*
argument_list|>
argument_list|(
name|window
argument_list|)
decl_stmt|;
name|QSize
name|size
argument_list|(
name|eglWindow
operator|->
name|width
argument_list|,
name|eglWindow
operator|->
name|height
argument_list|)
decl_stmt|;
name|VC_RECT_T
name|dst_rect
decl_stmt|;
name|dst_rect
operator|.
name|x
operator|=
name|pos
operator|.
name|x
argument_list|()
expr_stmt|;
name|dst_rect
operator|.
name|y
operator|=
name|pos
operator|.
name|y
argument_list|()
expr_stmt|;
name|dst_rect
operator|.
name|width
operator|=
name|size
operator|.
name|width
argument_list|()
expr_stmt|;
name|dst_rect
operator|.
name|height
operator|=
name|size
operator|.
name|height
argument_list|()
expr_stmt|;
name|VC_RECT_T
name|src_rect
decl_stmt|;
name|src_rect
operator|.
name|x
operator|=
literal|0
expr_stmt|;
name|src_rect
operator|.
name|y
operator|=
literal|0
expr_stmt|;
name|src_rect
operator|.
name|width
operator|=
name|size
operator|.
name|width
argument_list|()
operator|<<
literal|16
expr_stmt|;
name|src_rect
operator|.
name|height
operator|=
name|size
operator|.
name|height
argument_list|()
operator|<<
literal|16
expr_stmt|;
name|DISPMANX_UPDATE_HANDLE_T
name|dispman_update
init|=
name|vc_dispmanx_update_start
argument_list|(
literal|0
argument_list|)
decl_stmt|;
name|vc_dispmanx_element_change_attributes
argument_list|(
name|dispman_update
argument_list|,
name|eglWindow
operator|->
name|element
argument_list|,
name|ELEMENT_CHANGE_DEST_RECT
comment|/*change_flags*/
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
operator|&
name|dst_rect
argument_list|,
name|NULL
argument_list|,
literal|0
argument_list|,
operator|(
name|VC_IMAGE_TRANSFORM_T
operator|)
literal|0
argument_list|)
expr_stmt|;
name|vc_dispmanx_update_submit_sync
argument_list|(
name|dispman_update
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|destroyDispmanxLayer
specifier|static
name|void
name|destroyDispmanxLayer
parameter_list|(
name|EGLNativeWindowType
name|window
parameter_list|)
block|{
name|EGL_DISPMANX_WINDOW_T
modifier|*
name|eglWindow
init|=
cast|static_cast
argument_list|<
name|EGL_DISPMANX_WINDOW_T
operator|*
argument_list|>
argument_list|(
name|window
argument_list|)
decl_stmt|;
name|DISPMANX_UPDATE_HANDLE_T
name|dispman_update
init|=
name|vc_dispmanx_update_start
argument_list|(
literal|0
argument_list|)
decl_stmt|;
name|vc_dispmanx_element_remove
argument_list|(
name|dispman_update
argument_list|,
name|eglWindow
operator|->
name|element
argument_list|)
expr_stmt|;
name|vc_dispmanx_update_submit_sync
argument_list|(
name|dispman_update
argument_list|)
expr_stmt|;
operator|delete
name|eglWindow
expr_stmt|;
block|}
end_function
begin_class
DECL|class|QEglFSPiCursor
class|class
name|QEglFSPiCursor
super|:
specifier|public
name|QEglFSCursor
block|{
public|public:
DECL|function|QEglFSPiCursor
name|QEglFSPiCursor
parameter_list|(
name|QEglFSScreen
modifier|*
name|screen
parameter_list|)
member_init_list|:
name|QEglFSCursor
argument_list|(
name|screen
argument_list|)
block|{
name|QSurfaceFormat
name|platformFormat
decl_stmt|;
name|platformFormat
operator|.
name|setDepthBufferSize
argument_list|(
literal|24
argument_list|)
expr_stmt|;
name|platformFormat
operator|.
name|setStencilBufferSize
argument_list|(
literal|8
argument_list|)
expr_stmt|;
name|platformFormat
operator|.
name|setRedBufferSize
argument_list|(
literal|8
argument_list|)
expr_stmt|;
name|platformFormat
operator|.
name|setGreenBufferSize
argument_list|(
literal|8
argument_list|)
expr_stmt|;
name|platformFormat
operator|.
name|setBlueBufferSize
argument_list|(
literal|8
argument_list|)
expr_stmt|;
name|platformFormat
operator|.
name|setAlphaBufferSize
argument_list|(
literal|8
argument_list|)
expr_stmt|;
name|m_config
operator|=
name|q_configFromGLFormat
argument_list|(
name|m_screen
operator|->
name|display
argument_list|()
argument_list|,
name|platformFormat
argument_list|)
expr_stmt|;
name|createSurface
argument_list|()
expr_stmt|;
name|createContext
argument_list|()
expr_stmt|;
name|drawInLayer
argument_list|()
expr_stmt|;
block|}
DECL|function|~QEglFSPiCursor
name|~
name|QEglFSPiCursor
parameter_list|()
block|{
name|eglDestroySurface
argument_list|(
name|m_screen
operator|->
name|display
argument_list|()
argument_list|,
name|m_surface
argument_list|)
expr_stmt|;
name|destroyDispmanxLayer
argument_list|(
name|m_window
argument_list|)
expr_stmt|;
name|eglDestroyContext
argument_list|(
name|m_screen
operator|->
name|display
argument_list|()
argument_list|,
name|m_context
argument_list|)
expr_stmt|;
block|}
DECL|function|createSurface
name|void
name|createSurface
parameter_list|()
block|{
specifier|const
name|QRect
name|cr
init|=
name|cursorRect
argument_list|()
decl_stmt|;
name|m_window
operator|=
name|createDispmanxLayer
argument_list|(
name|cr
operator|.
name|topLeft
argument_list|()
argument_list|,
name|cr
operator|.
name|size
argument_list|()
argument_list|,
literal|50
argument_list|,
name|DISPMANX_FLAGS_ALPHA_FROM_SOURCE
argument_list|)
expr_stmt|;
name|m_surface
operator|=
name|eglCreateWindowSurface
argument_list|(
name|m_screen
operator|->
name|display
argument_list|()
argument_list|,
name|m_config
argument_list|,
name|m_window
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
block|}
DECL|function|createContext
name|void
name|createContext
parameter_list|()
block|{
name|eglBindAPI
argument_list|(
name|EGL_OPENGL_ES_API
argument_list|)
expr_stmt|;
name|QVector
argument_list|<
name|EGLint
argument_list|>
name|attrs
decl_stmt|;
name|attrs
operator|.
name|append
argument_list|(
name|EGL_CONTEXT_CLIENT_VERSION
argument_list|)
expr_stmt|;
name|attrs
operator|.
name|append
argument_list|(
literal|2
argument_list|)
expr_stmt|;
name|attrs
operator|.
name|append
argument_list|(
name|EGL_NONE
argument_list|)
expr_stmt|;
name|m_context
operator|=
name|eglCreateContext
argument_list|(
name|m_screen
operator|->
name|display
argument_list|()
argument_list|,
name|m_config
argument_list|,
name|EGL_NO_CONTEXT
argument_list|,
name|attrs
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
block|}
DECL|function|drawInLayer
name|void
name|drawInLayer
parameter_list|()
block|{
name|eglMakeCurrent
argument_list|(
name|m_screen
operator|->
name|display
argument_list|()
argument_list|,
name|m_surface
argument_list|,
name|m_surface
argument_list|,
name|m_context
argument_list|)
expr_stmt|;
name|glClearColor
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|glClear
argument_list|(
name|GL_COLOR_BUFFER_BIT
argument_list|)
expr_stmt|;
name|draw
argument_list|(
name|QRectF
argument_list|(
name|QPointF
argument_list|(
operator|-
literal|1
argument_list|,
literal|1
argument_list|)
argument_list|,
name|QPointF
argument_list|(
literal|1
argument_list|,
operator|-
literal|1
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|eglSwapBuffers
argument_list|(
name|m_screen
operator|->
name|display
argument_list|()
argument_list|,
name|m_surface
argument_list|)
expr_stmt|;
name|eglMakeCurrent
argument_list|(
name|m_screen
operator|->
name|display
argument_list|()
argument_list|,
name|EGL_NO_SURFACE
argument_list|,
name|EGL_NO_SURFACE
argument_list|,
name|EGL_NO_CONTEXT
argument_list|)
expr_stmt|;
block|}
DECL|function|changeCursor
name|void
name|changeCursor
parameter_list|(
name|QCursor
modifier|*
name|cursor
parameter_list|,
name|QWindow
modifier|*
name|window
parameter_list|)
block|{
if|if
condition|(
operator|!
name|setCurrentCursor
argument_list|(
name|cursor
argument_list|)
condition|)
return|return;
name|EGL_DISPMANX_WINDOW_T
modifier|*
name|eglWindow
init|=
cast|static_cast
argument_list|<
name|EGL_DISPMANX_WINDOW_T
operator|*
argument_list|>
argument_list|(
name|m_window
argument_list|)
decl_stmt|;
if|if
condition|(
name|QSize
argument_list|(
name|eglWindow
operator|->
name|width
argument_list|,
name|eglWindow
operator|->
name|height
argument_list|)
operator|!=
name|m_cursor
operator|.
name|size
condition|)
block|{
name|eglDestroySurface
argument_list|(
name|m_screen
operator|->
name|display
argument_list|()
argument_list|,
name|m_surface
argument_list|)
expr_stmt|;
name|destroyDispmanxLayer
argument_list|(
name|m_window
argument_list|)
expr_stmt|;
name|createSurface
argument_list|()
expr_stmt|;
block|}
name|drawInLayer
argument_list|()
expr_stmt|;
block|}
DECL|function|setPos
name|void
name|setPos
parameter_list|(
specifier|const
name|QPoint
modifier|&
name|pos
parameter_list|)
block|{
name|m_pos
operator|=
name|pos
expr_stmt|;
name|moveDispmanxLayer
argument_list|(
name|m_window
argument_list|,
name|cursorRect
argument_list|()
operator|.
name|topLeft
argument_list|()
argument_list|)
expr_stmt|;
block|}
DECL|function|pointerEvent
name|void
name|pointerEvent
parameter_list|(
specifier|const
name|QMouseEvent
modifier|&
name|event
parameter_list|)
block|{
if|if
condition|(
name|event
operator|.
name|type
argument_list|()
operator|!=
name|QEvent
operator|::
name|MouseMove
condition|)
return|return;
name|m_pos
operator|=
name|event
operator|.
name|pos
argument_list|()
expr_stmt|;
name|moveDispmanxLayer
argument_list|(
name|m_window
argument_list|,
name|cursorRect
argument_list|()
operator|.
name|topLeft
argument_list|()
argument_list|)
expr_stmt|;
block|}
DECL|function|paintOnScreen
name|void
name|paintOnScreen
parameter_list|()
block|{ }
private|private:
DECL|member|m_config
name|EGLConfig
name|m_config
decl_stmt|;
DECL|member|m_context
name|EGLContext
name|m_context
decl_stmt|;
DECL|member|m_window
name|EGLNativeWindowType
name|m_window
decl_stmt|;
DECL|member|m_surface
name|EGLSurface
name|m_surface
decl_stmt|;
block|}
class|;
end_class
begin_class
DECL|class|QEglFSPiHooks
class|class
name|QEglFSPiHooks
super|:
specifier|public
name|QEglFSHooks
block|{
public|public:
specifier|virtual
name|void
name|platformInit
parameter_list|()
function_decl|;
specifier|virtual
name|void
name|platformDestroy
parameter_list|()
function_decl|;
specifier|virtual
name|EGLNativeDisplayType
name|platformDisplay
parameter_list|()
specifier|const
function_decl|;
specifier|virtual
name|QSize
name|screenSize
parameter_list|()
specifier|const
function_decl|;
specifier|virtual
name|EGLNativeWindowType
name|createNativeWindow
parameter_list|(
specifier|const
name|QSize
modifier|&
name|size
parameter_list|)
function_decl|;
specifier|virtual
name|void
name|destroyNativeWindow
parameter_list|(
name|EGLNativeWindowType
name|window
parameter_list|)
function_decl|;
specifier|virtual
name|bool
name|hasCapability
parameter_list|(
name|QPlatformIntegration
operator|::
name|Capability
name|cap
parameter_list|)
specifier|const
function_decl|;
DECL|function|createCursor
name|QEglFSCursor
modifier|*
name|createCursor
parameter_list|(
name|QEglFSScreen
modifier|*
name|screen
parameter_list|)
specifier|const
block|{
return|return
operator|new
name|QEglFSPiCursor
argument_list|(
name|screen
argument_list|)
return|;
block|}
block|}
class|;
end_class
begin_function
DECL|function|platformInit
name|void
name|QEglFSPiHooks
operator|::
name|platformInit
parameter_list|()
block|{
name|bcm_host_init
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|platformDisplay
name|EGLNativeDisplayType
name|QEglFSPiHooks
operator|::
name|platformDisplay
parameter_list|()
specifier|const
block|{
name|dispman_display
operator|=
name|vc_dispmanx_display_open
argument_list|(
literal|0
comment|/* LCD */
argument_list|)
expr_stmt|;
return|return
name|EGL_DEFAULT_DISPLAY
return|;
block|}
end_function
begin_function
DECL|function|platformDestroy
name|void
name|QEglFSPiHooks
operator|::
name|platformDestroy
parameter_list|()
block|{
name|vc_dispmanx_display_close
argument_list|(
name|dispman_display
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|screenSize
name|QSize
name|QEglFSPiHooks
operator|::
name|screenSize
parameter_list|()
specifier|const
block|{
comment|//both mechanisms work
if|#
directive|if
literal|1
name|uint32_t
name|width
decl_stmt|,
name|height
decl_stmt|;
name|graphics_get_display_size
argument_list|(
literal|0
comment|/* LCD */
argument_list|,
operator|&
name|width
argument_list|,
operator|&
name|height
argument_list|)
expr_stmt|;
return|return
name|QSize
argument_list|(
name|width
argument_list|,
name|height
argument_list|)
return|;
else|#
directive|else
name|int
name|fd
init|=
name|open
argument_list|(
literal|"/dev/fb0"
argument_list|,
name|O_RDONLY
argument_list|)
decl_stmt|;
if|if
condition|(
name|fd
operator|==
operator|-
literal|1
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Failed to open fb to detect screen resolution!\n"
argument_list|)
expr_stmt|;
return|return
name|QSize
argument_list|()
return|;
block|}
name|struct
name|fb_var_screeninfo
name|vinfo
decl_stmt|;
if|if
condition|(
name|ioctl
argument_list|(
name|fd
argument_list|,
name|FBIOGET_VSCREENINFO
argument_list|,
operator|&
name|vinfo
argument_list|)
operator|=
operator|-
literal|1
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Could not query screen info variable\n"
argument_list|)
expr_stmt|;
name|close
argument_list|(
name|fd
argument_list|)
expr_stmt|;
return|return
name|QSize
argument_list|()
return|;
block|}
name|close
argument_list|(
name|fd
argument_list|)
expr_stmt|;
return|return
name|QSize
argument_list|(
name|vinfo
operator|.
name|xres
argument_list|,
name|vinfo
operator|.
name|yres
argument_list|)
return|;
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|createNativeWindow
name|EGLNativeWindowType
name|QEglFSPiHooks
operator|::
name|createNativeWindow
parameter_list|(
specifier|const
name|QSize
modifier|&
name|size
parameter_list|)
block|{
return|return
name|createDispmanxLayer
argument_list|(
name|QPoint
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|,
name|size
argument_list|,
literal|1
argument_list|,
name|DISPMANX_FLAGS_ALPHA_FIXED_ALL_PIXELS
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|destroyNativeWindow
name|void
name|QEglFSPiHooks
operator|::
name|destroyNativeWindow
parameter_list|(
name|EGLNativeWindowType
name|window
parameter_list|)
block|{
name|destroyDispmanxLayer
argument_list|(
name|window
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|hasCapability
name|bool
name|QEglFSPiHooks
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
name|QPlatformIntegration
operator|::
name|ThreadedPixmaps
case|:
case|case
name|QPlatformIntegration
operator|::
name|OpenGL
case|:
case|case
name|QPlatformIntegration
operator|::
name|ThreadedOpenGL
case|:
case|case
name|QPlatformIntegration
operator|::
name|BufferQueueingOpenGL
case|:
return|return
literal|true
return|;
default|default:
return|return
literal|false
return|;
block|}
block|}
end_function
begin_decl_stmt
DECL|variable|eglFSPiHooks
name|QEglFSPiHooks
name|eglFSPiHooks
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|platformHooks
name|QEglFSHooks
modifier|*
name|platformHooks
init|=
operator|&
name|eglFSPiHooks
decl_stmt|;
end_decl_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
