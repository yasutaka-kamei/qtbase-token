begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qeglfsmaliintegration.h"
end_include
begin_include
include|#
directive|include
file|<EGL/fbdev_window.h>
end_include
begin_include
include|#
directive|include
file|<unistd.h>
end_include
begin_include
include|#
directive|include
file|<fcntl.h>
end_include
begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include
begin_include
include|#
directive|include
file|<linux/fb.h>
end_include
begin_include
include|#
directive|include
file|<private/qcore_unix_p.h>
end_include
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|platformInit
name|void
name|QEglFSMaliIntegration
operator|::
name|platformInit
parameter_list|()
block|{
comment|// Keep the non-overridden base class functions based on fb0 working.
name|QEGLDeviceIntegration
operator|::
name|platformInit
argument_list|()
expr_stmt|;
name|int
name|fd
init|=
name|qt_safe_open
argument_list|(
literal|"/dev/fb0"
argument_list|,
name|O_RDWR
argument_list|,
literal|0
argument_list|)
decl_stmt|;
if|if
condition|(
name|fd
operator|==
operator|-
literal|1
condition|)
name|qWarning
argument_list|(
literal|"Failed to open fb to detect screen resolution!"
argument_list|)
expr_stmt|;
name|struct
name|fb_var_screeninfo
name|vinfo
decl_stmt|;
name|memset
argument_list|(
operator|&
name|vinfo
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|vinfo
argument_list|)
argument_list|)
expr_stmt|;
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
operator|==
operator|-
literal|1
condition|)
name|qWarning
argument_list|(
literal|"Could not get variable screen info"
argument_list|)
expr_stmt|;
name|vinfo
operator|.
name|bits_per_pixel
operator|=
literal|32
expr_stmt|;
name|vinfo
operator|.
name|red
operator|.
name|length
operator|=
literal|8
expr_stmt|;
name|vinfo
operator|.
name|green
operator|.
name|length
operator|=
literal|8
expr_stmt|;
name|vinfo
operator|.
name|blue
operator|.
name|length
operator|=
literal|8
expr_stmt|;
name|vinfo
operator|.
name|transp
operator|.
name|length
operator|=
literal|8
expr_stmt|;
name|vinfo
operator|.
name|blue
operator|.
name|offset
operator|=
literal|0
expr_stmt|;
name|vinfo
operator|.
name|green
operator|.
name|offset
operator|=
literal|8
expr_stmt|;
name|vinfo
operator|.
name|red
operator|.
name|offset
operator|=
literal|16
expr_stmt|;
name|vinfo
operator|.
name|transp
operator|.
name|offset
operator|=
literal|24
expr_stmt|;
name|vinfo
operator|.
name|yres_virtual
operator|=
literal|2
operator|*
name|vinfo
operator|.
name|yres
expr_stmt|;
if|if
condition|(
name|ioctl
argument_list|(
name|fd
argument_list|,
name|FBIOPUT_VSCREENINFO
argument_list|,
operator|&
name|vinfo
argument_list|)
operator|==
operator|-
literal|1
condition|)
name|qErrnoWarning
argument_list|(
name|errno
argument_list|,
literal|"Unable to set double buffer mode!"
argument_list|)
expr_stmt|;
name|qt_safe_close
argument_list|(
name|fd
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|createNativeWindow
name|EGLNativeWindowType
name|QEglFSMaliIntegration
operator|::
name|createNativeWindow
parameter_list|(
name|QPlatformWindow
modifier|*
name|window
parameter_list|,
specifier|const
name|QSize
modifier|&
name|size
parameter_list|,
specifier|const
name|QSurfaceFormat
modifier|&
name|format
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|window
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|format
argument_list|)
expr_stmt|;
name|fbdev_window
modifier|*
name|fbwin
init|=
cast|reinterpret_cast
argument_list|<
name|fbdev_window
operator|*
argument_list|>
argument_list|(
name|malloc
argument_list|(
sizeof|sizeof
argument_list|(
name|fbdev_window
argument_list|)
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|NULL
operator|==
name|fbwin
condition|)
return|return
literal|0
return|;
name|fbwin
operator|->
name|width
operator|=
name|size
operator|.
name|width
argument_list|()
expr_stmt|;
name|fbwin
operator|->
name|height
operator|=
name|size
operator|.
name|height
argument_list|()
expr_stmt|;
return|return
operator|(
name|EGLNativeWindowType
operator|)
name|fbwin
return|;
block|}
end_function
begin_function
DECL|function|destroyNativeWindow
name|void
name|QEglFSMaliIntegration
operator|::
name|destroyNativeWindow
parameter_list|(
name|EGLNativeWindowType
name|window
parameter_list|)
block|{
name|free
argument_list|(
name|window
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit