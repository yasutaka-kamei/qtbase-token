begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the qmake spec of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qeglfs_hooks.h"
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
DECL|variable|dispman_display
specifier|static
name|DISPMANX_DISPLAY_HANDLE_T
name|dispman_display
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|dispman_update
specifier|static
name|DISPMANX_UPDATE_HANDLE_T
name|dispman_update
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|platformInit
name|void
name|QEglFSHooks
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
name|QEglFSHooks
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
name|QEglFSHooks
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
name|QEglFSHooks
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
name|QEglFSHooks
operator|::
name|createNativeWindow
parameter_list|(
specifier|const
name|QSize
modifier|&
name|size
parameter_list|)
block|{
name|VC_RECT_T
name|dst_rect
decl_stmt|;
name|dst_rect
operator|.
name|x
operator|=
literal|0
expr_stmt|;
name|dst_rect
operator|.
name|y
operator|=
literal|0
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
name|dispman_update
operator|=
name|vc_dispmanx_update_start
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|VC_DISPMANX_ALPHA_T
name|alpha
decl_stmt|;
name|alpha
operator|.
name|flags
operator|=
name|DISPMANX_FLAGS_ALPHA_FIXED_ALL_PIXELS
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
literal|0
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
begin_function
DECL|function|destroyNativeWindow
name|void
name|QEglFSHooks
operator|::
name|destroyNativeWindow
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
name|vc_dispmanx_element_remove
argument_list|(
name|dispman_update
argument_list|,
name|eglWindow
operator|->
name|element
argument_list|)
expr_stmt|;
operator|delete
name|eglWindow
expr_stmt|;
block|}
end_function
begin_decl_stmt
DECL|variable|platform_hooks
name|QEglFSHooks
name|platform_hooks
decl_stmt|;
end_decl_stmt
end_unit
