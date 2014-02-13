begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qlinuxfbscreen.h"
end_include
begin_include
include|#
directive|include
file|<QtPlatformSupport/private/qfbcursor_p.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/QRegularExpression>
end_include
begin_include
include|#
directive|include
file|<QtGui/QPainter>
end_include
begin_include
include|#
directive|include
file|<private/qcore_unix_p.h>
end_include
begin_comment
comment|// overrides QT_OPEN
end_comment
begin_include
include|#
directive|include
file|<qimage.h>
end_include
begin_include
include|#
directive|include
file|<qdebug.h>
end_include
begin_include
include|#
directive|include
file|<unistd.h>
end_include
begin_include
include|#
directive|include
file|<stdlib.h>
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
file|<sys/mman.h>
end_include
begin_include
include|#
directive|include
file|<linux/kd.h>
end_include
begin_include
include|#
directive|include
file|<fcntl.h>
end_include
begin_include
include|#
directive|include
file|<errno.h>
end_include
begin_include
include|#
directive|include
file|<stdio.h>
end_include
begin_include
include|#
directive|include
file|<limits.h>
end_include
begin_include
include|#
directive|include
file|<signal.h>
end_include
begin_include
include|#
directive|include
file|<linux/fb.h>
end_include
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
file|<QtPlatformSupport/private/qdevicediscovery_p.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|openFramebufferDevice
specifier|static
name|int
name|openFramebufferDevice
parameter_list|(
specifier|const
name|QString
modifier|&
name|dev
parameter_list|)
block|{
name|int
name|fd
init|=
operator|-
literal|1
decl_stmt|;
if|if
condition|(
name|access
argument_list|(
name|dev
operator|.
name|toLatin1
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|,
name|R_OK
operator||
name|W_OK
argument_list|)
operator|==
literal|0
condition|)
name|fd
operator|=
name|QT_OPEN
argument_list|(
name|dev
operator|.
name|toLatin1
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|,
name|O_RDWR
argument_list|)
expr_stmt|;
if|if
condition|(
name|fd
operator|==
operator|-
literal|1
condition|)
block|{
if|if
condition|(
name|access
argument_list|(
name|dev
operator|.
name|toLatin1
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|,
name|R_OK
argument_list|)
operator|==
literal|0
condition|)
name|fd
operator|=
name|QT_OPEN
argument_list|(
name|dev
operator|.
name|toLatin1
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|,
name|O_RDONLY
argument_list|)
expr_stmt|;
block|}
return|return
name|fd
return|;
block|}
end_function
begin_function
DECL|function|determineDepth
specifier|static
name|int
name|determineDepth
parameter_list|(
specifier|const
name|fb_var_screeninfo
modifier|&
name|vinfo
parameter_list|)
block|{
name|int
name|depth
init|=
name|vinfo
operator|.
name|bits_per_pixel
decl_stmt|;
if|if
condition|(
name|depth
operator|==
literal|24
condition|)
block|{
name|depth
operator|=
name|vinfo
operator|.
name|red
operator|.
name|length
operator|+
name|vinfo
operator|.
name|green
operator|.
name|length
operator|+
name|vinfo
operator|.
name|blue
operator|.
name|length
expr_stmt|;
if|if
condition|(
name|depth
operator|<=
literal|0
condition|)
name|depth
operator|=
literal|24
expr_stmt|;
comment|// reset if color component lengths are not reported
block|}
elseif|else
if|if
condition|(
name|depth
operator|==
literal|16
condition|)
block|{
name|depth
operator|=
name|vinfo
operator|.
name|red
operator|.
name|length
operator|+
name|vinfo
operator|.
name|green
operator|.
name|length
operator|+
name|vinfo
operator|.
name|blue
operator|.
name|length
expr_stmt|;
if|if
condition|(
name|depth
operator|<=
literal|0
condition|)
name|depth
operator|=
literal|16
expr_stmt|;
block|}
return|return
name|depth
return|;
block|}
end_function
begin_function
DECL|function|determineGeometry
specifier|static
name|QRect
name|determineGeometry
parameter_list|(
specifier|const
name|fb_var_screeninfo
modifier|&
name|vinfo
parameter_list|,
specifier|const
name|QRect
modifier|&
name|userGeometry
parameter_list|)
block|{
name|int
name|xoff
init|=
name|vinfo
operator|.
name|xoffset
decl_stmt|;
name|int
name|yoff
init|=
name|vinfo
operator|.
name|yoffset
decl_stmt|;
name|int
name|w
decl_stmt|,
name|h
decl_stmt|;
if|if
condition|(
name|userGeometry
operator|.
name|isValid
argument_list|()
condition|)
block|{
name|w
operator|=
name|userGeometry
operator|.
name|width
argument_list|()
expr_stmt|;
name|h
operator|=
name|userGeometry
operator|.
name|height
argument_list|()
expr_stmt|;
if|if
condition|(
operator|(
name|uint
operator|)
name|w
operator|>
name|vinfo
operator|.
name|xres
condition|)
name|w
operator|=
name|vinfo
operator|.
name|xres
expr_stmt|;
if|if
condition|(
operator|(
name|uint
operator|)
name|h
operator|>
name|vinfo
operator|.
name|yres
condition|)
name|h
operator|=
name|vinfo
operator|.
name|yres
expr_stmt|;
name|int
name|xxoff
init|=
name|userGeometry
operator|.
name|x
argument_list|()
decl_stmt|,
name|yyoff
init|=
name|userGeometry
operator|.
name|y
argument_list|()
decl_stmt|;
if|if
condition|(
name|xxoff
operator|!=
literal|0
operator|||
name|yyoff
operator|!=
literal|0
condition|)
block|{
if|if
condition|(
name|xxoff
argument_list|<
literal|0
operator|||
name|xxoff
operator|+
name|w
argument_list|>
argument_list|(
name|int
argument_list|)
argument_list|(
name|vinfo
operator|.
name|xres
argument_list|)
condition|)
name|xxoff
operator|=
name|vinfo
operator|.
name|xres
operator|-
name|w
expr_stmt|;
if|if
condition|(
name|yyoff
argument_list|<
literal|0
operator|||
name|yyoff
operator|+
name|h
argument_list|>
argument_list|(
name|int
argument_list|)
argument_list|(
name|vinfo
operator|.
name|yres
argument_list|)
condition|)
name|yyoff
operator|=
name|vinfo
operator|.
name|yres
operator|-
name|h
expr_stmt|;
name|xoff
operator|+=
name|xxoff
expr_stmt|;
name|yoff
operator|+=
name|yyoff
expr_stmt|;
block|}
else|else
block|{
name|xoff
operator|+=
operator|(
name|vinfo
operator|.
name|xres
operator|-
name|w
operator|)
operator|/
literal|2
expr_stmt|;
name|yoff
operator|+=
operator|(
name|vinfo
operator|.
name|yres
operator|-
name|h
operator|)
operator|/
literal|2
expr_stmt|;
block|}
block|}
else|else
block|{
name|w
operator|=
name|vinfo
operator|.
name|xres
expr_stmt|;
name|h
operator|=
name|vinfo
operator|.
name|yres
expr_stmt|;
block|}
if|if
condition|(
name|w
operator|==
literal|0
operator|||
name|h
operator|==
literal|0
condition|)
block|{
name|qWarning
argument_list|(
literal|"Unable to find screen geometry, using 320x240"
argument_list|)
expr_stmt|;
name|w
operator|=
literal|320
expr_stmt|;
name|h
operator|=
literal|240
expr_stmt|;
block|}
return|return
name|QRect
argument_list|(
name|xoff
argument_list|,
name|yoff
argument_list|,
name|w
argument_list|,
name|h
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|determinePhysicalSize
specifier|static
name|QSizeF
name|determinePhysicalSize
parameter_list|(
specifier|const
name|fb_var_screeninfo
modifier|&
name|vinfo
parameter_list|,
specifier|const
name|QSize
modifier|&
name|mmSize
parameter_list|,
specifier|const
name|QSize
modifier|&
name|res
parameter_list|)
block|{
name|int
name|mmWidth
init|=
name|mmSize
operator|.
name|width
argument_list|()
decl_stmt|,
name|mmHeight
init|=
name|mmSize
operator|.
name|height
argument_list|()
decl_stmt|;
if|if
condition|(
name|mmWidth
operator|<=
literal|0
operator|&&
name|mmHeight
operator|<=
literal|0
condition|)
block|{
if|if
condition|(
name|vinfo
operator|.
name|width
operator|!=
literal|0
operator|&&
name|vinfo
operator|.
name|height
operator|!=
literal|0
operator|&&
name|vinfo
operator|.
name|width
operator|!=
name|UINT_MAX
operator|&&
name|vinfo
operator|.
name|height
operator|!=
name|UINT_MAX
condition|)
block|{
name|mmWidth
operator|=
name|vinfo
operator|.
name|width
expr_stmt|;
name|mmHeight
operator|=
name|vinfo
operator|.
name|height
expr_stmt|;
block|}
else|else
block|{
specifier|const
name|int
name|dpi
init|=
literal|72
decl_stmt|;
name|mmWidth
operator|=
name|qRound
argument_list|(
name|res
operator|.
name|width
argument_list|()
operator|*
literal|25.4
operator|/
name|dpi
argument_list|)
expr_stmt|;
name|mmHeight
operator|=
name|qRound
argument_list|(
name|res
operator|.
name|height
argument_list|()
operator|*
literal|25.4
operator|/
name|dpi
argument_list|)
expr_stmt|;
block|}
block|}
elseif|else
if|if
condition|(
name|mmWidth
operator|>
literal|0
operator|&&
name|mmHeight
operator|<=
literal|0
condition|)
block|{
name|mmHeight
operator|=
name|res
operator|.
name|height
argument_list|()
operator|*
name|mmWidth
operator|/
name|res
operator|.
name|width
argument_list|()
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|mmHeight
operator|>
literal|0
operator|&&
name|mmWidth
operator|<=
literal|0
condition|)
block|{
name|mmWidth
operator|=
name|res
operator|.
name|width
argument_list|()
operator|*
name|mmHeight
operator|/
name|res
operator|.
name|height
argument_list|()
expr_stmt|;
block|}
return|return
name|QSize
argument_list|(
name|mmWidth
argument_list|,
name|mmHeight
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|determineFormat
specifier|static
name|QImage
operator|::
name|Format
name|determineFormat
parameter_list|(
specifier|const
name|fb_var_screeninfo
modifier|&
name|info
parameter_list|,
name|int
name|depth
parameter_list|)
block|{
specifier|const
name|fb_bitfield
name|rgba
index|[
literal|4
index|]
init|=
block|{
name|info
operator|.
name|red
block|,
name|info
operator|.
name|green
block|,
name|info
operator|.
name|blue
block|,
name|info
operator|.
name|transp
block|}
decl_stmt|;
name|QImage
operator|::
name|Format
name|format
init|=
name|QImage
operator|::
name|Format_Invalid
decl_stmt|;
switch|switch
condition|(
name|depth
condition|)
block|{
case|case
literal|32
case|:
block|{
specifier|const
name|fb_bitfield
name|argb8888
index|[
literal|4
index|]
init|=
block|{
block|{
literal|16
block|,
literal|8
block|,
literal|0
block|}
block|,
block|{
literal|8
block|,
literal|8
block|,
literal|0
block|}
block|,
block|{
literal|0
block|,
literal|8
block|,
literal|0
block|}
block|,
block|{
literal|24
block|,
literal|8
block|,
literal|0
block|}
block|}
decl_stmt|;
specifier|const
name|fb_bitfield
name|abgr8888
index|[
literal|4
index|]
init|=
block|{
block|{
literal|0
block|,
literal|8
block|,
literal|0
block|}
block|,
block|{
literal|8
block|,
literal|8
block|,
literal|0
block|}
block|,
block|{
literal|16
block|,
literal|8
block|,
literal|0
block|}
block|,
block|{
literal|24
block|,
literal|8
block|,
literal|0
block|}
block|}
decl_stmt|;
if|if
condition|(
name|memcmp
argument_list|(
name|rgba
argument_list|,
name|argb8888
argument_list|,
literal|4
operator|*
sizeof|sizeof
argument_list|(
name|fb_bitfield
argument_list|)
argument_list|)
operator|==
literal|0
condition|)
block|{
name|format
operator|=
name|QImage
operator|::
name|Format_ARGB32
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|memcmp
argument_list|(
name|rgba
argument_list|,
name|argb8888
argument_list|,
literal|3
operator|*
sizeof|sizeof
argument_list|(
name|fb_bitfield
argument_list|)
argument_list|)
operator|==
literal|0
condition|)
block|{
name|format
operator|=
name|QImage
operator|::
name|Format_RGB32
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|memcmp
argument_list|(
name|rgba
argument_list|,
name|abgr8888
argument_list|,
literal|3
operator|*
sizeof|sizeof
argument_list|(
name|fb_bitfield
argument_list|)
argument_list|)
operator|==
literal|0
condition|)
block|{
name|format
operator|=
name|QImage
operator|::
name|Format_RGB32
expr_stmt|;
comment|// pixeltype = BGRPixel;
block|}
break|break;
block|}
case|case
literal|24
case|:
block|{
specifier|const
name|fb_bitfield
name|rgb888
index|[
literal|4
index|]
init|=
block|{
block|{
literal|16
block|,
literal|8
block|,
literal|0
block|}
block|,
block|{
literal|8
block|,
literal|8
block|,
literal|0
block|}
block|,
block|{
literal|0
block|,
literal|8
block|,
literal|0
block|}
block|,
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
specifier|const
name|fb_bitfield
name|bgr888
index|[
literal|4
index|]
init|=
block|{
block|{
literal|0
block|,
literal|8
block|,
literal|0
block|}
block|,
block|{
literal|8
block|,
literal|8
block|,
literal|0
block|}
block|,
block|{
literal|16
block|,
literal|8
block|,
literal|0
block|}
block|,
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
if|if
condition|(
name|memcmp
argument_list|(
name|rgba
argument_list|,
name|rgb888
argument_list|,
literal|3
operator|*
sizeof|sizeof
argument_list|(
name|fb_bitfield
argument_list|)
argument_list|)
operator|==
literal|0
condition|)
block|{
name|format
operator|=
name|QImage
operator|::
name|Format_RGB888
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|memcmp
argument_list|(
name|rgba
argument_list|,
name|bgr888
argument_list|,
literal|3
operator|*
sizeof|sizeof
argument_list|(
name|fb_bitfield
argument_list|)
argument_list|)
operator|==
literal|0
condition|)
block|{
name|format
operator|=
name|QImage
operator|::
name|Format_RGB888
expr_stmt|;
comment|// pixeltype = BGRPixel;
block|}
break|break;
block|}
case|case
literal|18
case|:
block|{
specifier|const
name|fb_bitfield
name|rgb666
index|[
literal|4
index|]
init|=
block|{
block|{
literal|12
block|,
literal|6
block|,
literal|0
block|}
block|,
block|{
literal|6
block|,
literal|6
block|,
literal|0
block|}
block|,
block|{
literal|0
block|,
literal|6
block|,
literal|0
block|}
block|,
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
if|if
condition|(
name|memcmp
argument_list|(
name|rgba
argument_list|,
name|rgb666
argument_list|,
literal|3
operator|*
sizeof|sizeof
argument_list|(
name|fb_bitfield
argument_list|)
argument_list|)
operator|==
literal|0
condition|)
name|format
operator|=
name|QImage
operator|::
name|Format_RGB666
expr_stmt|;
break|break;
block|}
case|case
literal|16
case|:
block|{
specifier|const
name|fb_bitfield
name|rgb565
index|[
literal|4
index|]
init|=
block|{
block|{
literal|11
block|,
literal|5
block|,
literal|0
block|}
block|,
block|{
literal|5
block|,
literal|6
block|,
literal|0
block|}
block|,
block|{
literal|0
block|,
literal|5
block|,
literal|0
block|}
block|,
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
specifier|const
name|fb_bitfield
name|bgr565
index|[
literal|4
index|]
init|=
block|{
block|{
literal|0
block|,
literal|5
block|,
literal|0
block|}
block|,
block|{
literal|5
block|,
literal|6
block|,
literal|0
block|}
block|,
block|{
literal|11
block|,
literal|5
block|,
literal|0
block|}
block|,
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
if|if
condition|(
name|memcmp
argument_list|(
name|rgba
argument_list|,
name|rgb565
argument_list|,
literal|3
operator|*
sizeof|sizeof
argument_list|(
name|fb_bitfield
argument_list|)
argument_list|)
operator|==
literal|0
condition|)
block|{
name|format
operator|=
name|QImage
operator|::
name|Format_RGB16
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|memcmp
argument_list|(
name|rgba
argument_list|,
name|bgr565
argument_list|,
literal|3
operator|*
sizeof|sizeof
argument_list|(
name|fb_bitfield
argument_list|)
argument_list|)
operator|==
literal|0
condition|)
block|{
name|format
operator|=
name|QImage
operator|::
name|Format_RGB16
expr_stmt|;
comment|// pixeltype = BGRPixel;
block|}
break|break;
block|}
case|case
literal|15
case|:
block|{
specifier|const
name|fb_bitfield
name|rgb1555
index|[
literal|4
index|]
init|=
block|{
block|{
literal|10
block|,
literal|5
block|,
literal|0
block|}
block|,
block|{
literal|5
block|,
literal|5
block|,
literal|0
block|}
block|,
block|{
literal|0
block|,
literal|5
block|,
literal|0
block|}
block|,
block|{
literal|15
block|,
literal|1
block|,
literal|0
block|}
block|}
decl_stmt|;
specifier|const
name|fb_bitfield
name|bgr1555
index|[
literal|4
index|]
init|=
block|{
block|{
literal|0
block|,
literal|5
block|,
literal|0
block|}
block|,
block|{
literal|5
block|,
literal|5
block|,
literal|0
block|}
block|,
block|{
literal|10
block|,
literal|5
block|,
literal|0
block|}
block|,
block|{
literal|15
block|,
literal|1
block|,
literal|0
block|}
block|}
decl_stmt|;
if|if
condition|(
name|memcmp
argument_list|(
name|rgba
argument_list|,
name|rgb1555
argument_list|,
literal|3
operator|*
sizeof|sizeof
argument_list|(
name|fb_bitfield
argument_list|)
argument_list|)
operator|==
literal|0
condition|)
block|{
name|format
operator|=
name|QImage
operator|::
name|Format_RGB555
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|memcmp
argument_list|(
name|rgba
argument_list|,
name|bgr1555
argument_list|,
literal|3
operator|*
sizeof|sizeof
argument_list|(
name|fb_bitfield
argument_list|)
argument_list|)
operator|==
literal|0
condition|)
block|{
name|format
operator|=
name|QImage
operator|::
name|Format_RGB555
expr_stmt|;
comment|// pixeltype = BGRPixel;
block|}
break|break;
block|}
case|case
literal|12
case|:
block|{
specifier|const
name|fb_bitfield
name|rgb444
index|[
literal|4
index|]
init|=
block|{
block|{
literal|8
block|,
literal|4
block|,
literal|0
block|}
block|,
block|{
literal|4
block|,
literal|4
block|,
literal|0
block|}
block|,
block|{
literal|0
block|,
literal|4
block|,
literal|0
block|}
block|,
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
if|if
condition|(
name|memcmp
argument_list|(
name|rgba
argument_list|,
name|rgb444
argument_list|,
literal|3
operator|*
sizeof|sizeof
argument_list|(
name|fb_bitfield
argument_list|)
argument_list|)
operator|==
literal|0
condition|)
name|format
operator|=
name|QImage
operator|::
name|Format_RGB444
expr_stmt|;
break|break;
block|}
case|case
literal|8
case|:
break|break;
case|case
literal|1
case|:
name|format
operator|=
name|QImage
operator|::
name|Format_Mono
expr_stmt|;
comment|//###: LSB???
break|break;
default|default:
break|break;
block|}
return|return
name|format
return|;
block|}
end_function
begin_function
DECL|function|openTtyDevice
specifier|static
name|int
name|openTtyDevice
parameter_list|(
specifier|const
name|QString
modifier|&
name|device
parameter_list|)
block|{
specifier|const
name|char
modifier|*
specifier|const
name|devs
index|[]
init|=
block|{
literal|"/dev/tty0"
block|,
literal|"/dev/tty"
block|,
literal|"/dev/console"
block|,
literal|0
block|}
decl_stmt|;
name|int
name|fd
init|=
operator|-
literal|1
decl_stmt|;
if|if
condition|(
name|device
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
for|for
control|(
specifier|const
name|char
modifier|*
specifier|const
modifier|*
name|dev
init|=
name|devs
init|;
operator|*
name|dev
condition|;
operator|++
name|dev
control|)
block|{
name|fd
operator|=
name|QT_OPEN
argument_list|(
operator|*
name|dev
argument_list|,
name|O_RDWR
argument_list|)
expr_stmt|;
if|if
condition|(
name|fd
operator|!=
operator|-
literal|1
condition|)
break|break;
block|}
block|}
else|else
block|{
name|fd
operator|=
name|QT_OPEN
argument_list|(
name|QFile
operator|::
name|encodeName
argument_list|(
name|device
argument_list|)
operator|.
name|constData
argument_list|()
argument_list|,
name|O_RDWR
argument_list|)
expr_stmt|;
block|}
return|return
name|fd
return|;
block|}
end_function
begin_function
DECL|function|switchToGraphicsMode
specifier|static
name|bool
name|switchToGraphicsMode
parameter_list|(
name|int
name|ttyfd
parameter_list|,
name|int
modifier|*
name|oldMode
parameter_list|)
block|{
name|ioctl
argument_list|(
name|ttyfd
argument_list|,
name|KDGETMODE
argument_list|,
name|oldMode
argument_list|)
expr_stmt|;
if|if
condition|(
operator|*
name|oldMode
operator|!=
name|KD_GRAPHICS
condition|)
block|{
if|if
condition|(
name|ioctl
argument_list|(
name|ttyfd
argument_list|,
name|KDSETMODE
argument_list|,
name|KD_GRAPHICS
argument_list|)
operator|!=
literal|0
condition|)
return|return
literal|false
return|;
block|}
comment|// No blankin' screen, no blinkin' cursor!, no cursor!
specifier|const
name|char
name|termctl
index|[]
init|=
literal|"\033[9;0]\033[?33l\033[?25l\033[?1c"
decl_stmt|;
name|QT_WRITE
argument_list|(
name|ttyfd
argument_list|,
name|termctl
argument_list|,
sizeof|sizeof
argument_list|(
name|termctl
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|resetTty
specifier|static
name|void
name|resetTty
parameter_list|(
name|int
name|ttyfd
parameter_list|,
name|int
name|oldMode
parameter_list|)
block|{
name|ioctl
argument_list|(
name|ttyfd
argument_list|,
name|KDSETMODE
argument_list|,
name|oldMode
argument_list|)
expr_stmt|;
comment|// Blankin' screen, blinkin' cursor!
specifier|const
name|char
name|termctl
index|[]
init|=
literal|"\033[9;15]\033[?33h\033[?25h\033[?0c"
decl_stmt|;
name|QT_WRITE
argument_list|(
name|ttyfd
argument_list|,
name|termctl
argument_list|,
sizeof|sizeof
argument_list|(
name|termctl
argument_list|)
argument_list|)
expr_stmt|;
name|QT_CLOSE
argument_list|(
name|ttyfd
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|blankScreen
specifier|static
name|void
name|blankScreen
parameter_list|(
name|int
name|fd
parameter_list|,
name|bool
name|on
parameter_list|)
block|{
name|ioctl
argument_list|(
name|fd
argument_list|,
name|FBIOBLANK
argument_list|,
name|on
condition|?
name|VESA_POWERDOWN
else|:
name|VESA_NO_BLANKING
argument_list|)
expr_stmt|;
block|}
end_function
begin_constructor
DECL|function|QLinuxFbScreen
name|QLinuxFbScreen
operator|::
name|QLinuxFbScreen
parameter_list|(
specifier|const
name|QStringList
modifier|&
name|args
parameter_list|)
member_init_list|:
name|mArgs
argument_list|(
name|args
argument_list|)
member_init_list|,
name|mFbFd
argument_list|(
operator|-
literal|1
argument_list|)
member_init_list|,
name|mBlitter
argument_list|(
literal|0
argument_list|)
block|{ }
end_constructor
begin_destructor
DECL|function|~QLinuxFbScreen
name|QLinuxFbScreen
operator|::
name|~
name|QLinuxFbScreen
parameter_list|()
block|{
if|if
condition|(
name|mFbFd
operator|!=
operator|-
literal|1
condition|)
block|{
name|munmap
argument_list|(
name|mMmap
operator|.
name|data
operator|-
name|mMmap
operator|.
name|offset
argument_list|,
name|mMmap
operator|.
name|size
argument_list|)
expr_stmt|;
name|close
argument_list|(
name|mFbFd
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|mTtyFd
operator|!=
operator|-
literal|1
condition|)
block|{
name|resetTty
argument_list|(
name|mTtyFd
argument_list|,
name|mOldTtyMode
argument_list|)
expr_stmt|;
name|close
argument_list|(
name|mTtyFd
argument_list|)
expr_stmt|;
block|}
operator|delete
name|mBlitter
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|initialize
name|bool
name|QLinuxFbScreen
operator|::
name|initialize
parameter_list|()
block|{
name|QRegularExpression
name|ttyRx
argument_list|(
name|QLatin1String
argument_list|(
literal|"tty=(.*)"
argument_list|)
argument_list|)
decl_stmt|;
name|QRegularExpression
name|fbRx
argument_list|(
name|QLatin1String
argument_list|(
literal|"fb=(.*)"
argument_list|)
argument_list|)
decl_stmt|;
name|QRegularExpression
name|mmSizeRx
argument_list|(
name|QLatin1String
argument_list|(
literal|"mmsize=(\\d+)x(\\d+)"
argument_list|)
argument_list|)
decl_stmt|;
name|QRegularExpression
name|sizeRx
argument_list|(
name|QLatin1String
argument_list|(
literal|"size=(\\d+)x(\\d+)"
argument_list|)
argument_list|)
decl_stmt|;
name|QRegularExpression
name|offsetRx
argument_list|(
name|QLatin1String
argument_list|(
literal|"offset=(\\d+)x(\\d+)"
argument_list|)
argument_list|)
decl_stmt|;
name|QString
name|fbDevice
decl_stmt|,
name|ttyDevice
decl_stmt|;
name|QSize
name|userMmSize
decl_stmt|;
name|QRect
name|userGeometry
decl_stmt|;
name|bool
name|doSwitchToGraphicsMode
init|=
literal|true
decl_stmt|;
comment|// Parse arguments
foreach|foreach
control|(
specifier|const
name|QString
modifier|&
name|arg
decl|,
name|mArgs
control|)
block|{
name|QRegularExpressionMatch
name|match
decl_stmt|;
if|if
condition|(
name|arg
operator|==
name|QLatin1String
argument_list|(
literal|"nographicsmodeswitch"
argument_list|)
condition|)
name|doSwitchToGraphicsMode
operator|=
literal|false
expr_stmt|;
elseif|else
if|if
condition|(
name|arg
operator|.
name|contains
argument_list|(
name|mmSizeRx
argument_list|,
operator|&
name|match
argument_list|)
condition|)
name|userMmSize
operator|=
name|QSize
argument_list|(
name|match
operator|.
name|captured
argument_list|(
literal|1
argument_list|)
operator|.
name|toInt
argument_list|()
argument_list|,
name|match
operator|.
name|captured
argument_list|(
literal|2
argument_list|)
operator|.
name|toInt
argument_list|()
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|arg
operator|.
name|contains
argument_list|(
name|sizeRx
argument_list|,
operator|&
name|match
argument_list|)
condition|)
name|userGeometry
operator|.
name|setSize
argument_list|(
name|QSize
argument_list|(
name|match
operator|.
name|captured
argument_list|(
literal|1
argument_list|)
operator|.
name|toInt
argument_list|()
argument_list|,
name|match
operator|.
name|captured
argument_list|(
literal|2
argument_list|)
operator|.
name|toInt
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|arg
operator|.
name|contains
argument_list|(
name|offsetRx
argument_list|,
operator|&
name|match
argument_list|)
condition|)
name|userGeometry
operator|.
name|setTopLeft
argument_list|(
name|QPoint
argument_list|(
name|match
operator|.
name|captured
argument_list|(
literal|1
argument_list|)
operator|.
name|toInt
argument_list|()
argument_list|,
name|match
operator|.
name|captured
argument_list|(
literal|2
argument_list|)
operator|.
name|toInt
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|arg
operator|.
name|contains
argument_list|(
name|ttyRx
argument_list|,
operator|&
name|match
argument_list|)
condition|)
name|ttyDevice
operator|=
name|match
operator|.
name|captured
argument_list|(
literal|1
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|arg
operator|.
name|contains
argument_list|(
name|fbRx
argument_list|,
operator|&
name|match
argument_list|)
condition|)
name|fbDevice
operator|=
name|match
operator|.
name|captured
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|fbDevice
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|fbDevice
operator|=
name|QLatin1String
argument_list|(
literal|"/dev/fb0"
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|QFile
operator|::
name|exists
argument_list|(
name|fbDevice
argument_list|)
condition|)
name|fbDevice
operator|=
name|QLatin1String
argument_list|(
literal|"/dev/graphics/fb0"
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|QFile
operator|::
name|exists
argument_list|(
name|fbDevice
argument_list|)
condition|)
block|{
name|qWarning
argument_list|(
literal|"Unable to figure out framebuffer device. Specify it manually."
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
block|}
comment|// Open the device
name|mFbFd
operator|=
name|openFramebufferDevice
argument_list|(
name|fbDevice
argument_list|)
expr_stmt|;
if|if
condition|(
name|mFbFd
operator|==
operator|-
literal|1
condition|)
block|{
name|qWarning
argument_list|(
literal|"Failed to open framebuffer %s : %s"
argument_list|,
name|qPrintable
argument_list|(
name|fbDevice
argument_list|)
argument_list|,
name|strerror
argument_list|(
name|errno
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
comment|// Read the fixed and variable screen information
name|fb_fix_screeninfo
name|finfo
decl_stmt|;
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
name|memset
argument_list|(
operator|&
name|finfo
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|finfo
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|ioctl
argument_list|(
name|mFbFd
argument_list|,
name|FBIOGET_FSCREENINFO
argument_list|,
operator|&
name|finfo
argument_list|)
operator|!=
literal|0
condition|)
block|{
name|qWarning
argument_list|(
literal|"Error reading fixed information: %s"
argument_list|,
name|strerror
argument_list|(
name|errno
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
if|if
condition|(
name|ioctl
argument_list|(
name|mFbFd
argument_list|,
name|FBIOGET_VSCREENINFO
argument_list|,
operator|&
name|vinfo
argument_list|)
condition|)
block|{
name|qWarning
argument_list|(
literal|"Error reading variable information: %s"
argument_list|,
name|strerror
argument_list|(
name|errno
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
name|mDepth
operator|=
name|determineDepth
argument_list|(
name|vinfo
argument_list|)
expr_stmt|;
name|mBytesPerLine
operator|=
name|finfo
operator|.
name|line_length
expr_stmt|;
name|QRect
name|geometry
init|=
name|determineGeometry
argument_list|(
name|vinfo
argument_list|,
name|userGeometry
argument_list|)
decl_stmt|;
name|mGeometry
operator|=
name|QRect
argument_list|(
name|QPoint
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|,
name|geometry
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
name|mFormat
operator|=
name|determineFormat
argument_list|(
name|vinfo
argument_list|,
name|mDepth
argument_list|)
expr_stmt|;
name|mPhysicalSize
operator|=
name|determinePhysicalSize
argument_list|(
name|vinfo
argument_list|,
name|userMmSize
argument_list|,
name|geometry
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
comment|// mmap the framebuffer
name|mMmap
operator|.
name|size
operator|=
name|finfo
operator|.
name|smem_len
expr_stmt|;
name|uchar
modifier|*
name|data
init|=
operator|(
name|unsigned
name|char
operator|*
operator|)
name|mmap
argument_list|(
literal|0
argument_list|,
name|mMmap
operator|.
name|size
argument_list|,
name|PROT_READ
operator||
name|PROT_WRITE
argument_list|,
name|MAP_SHARED
argument_list|,
name|mFbFd
argument_list|,
literal|0
argument_list|)
decl_stmt|;
if|if
condition|(
operator|(
name|long
operator|)
name|data
operator|==
operator|-
literal|1
condition|)
block|{
name|qWarning
argument_list|(
literal|"Failed to mmap framebuffer: %s"
argument_list|,
name|strerror
argument_list|(
name|errno
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
name|mMmap
operator|.
name|offset
operator|=
name|geometry
operator|.
name|y
argument_list|()
operator|*
name|mBytesPerLine
operator|+
name|geometry
operator|.
name|x
argument_list|()
operator|*
name|mDepth
operator|/
literal|8
expr_stmt|;
name|mMmap
operator|.
name|data
operator|=
name|data
operator|+
name|mMmap
operator|.
name|offset
expr_stmt|;
name|QFbScreen
operator|::
name|initializeCompositor
argument_list|()
expr_stmt|;
name|mFbScreenImage
operator|=
name|QImage
argument_list|(
name|mMmap
operator|.
name|data
argument_list|,
name|geometry
operator|.
name|width
argument_list|()
argument_list|,
name|geometry
operator|.
name|height
argument_list|()
argument_list|,
name|mBytesPerLine
argument_list|,
name|mFormat
argument_list|)
expr_stmt|;
name|QByteArray
name|hideCursorVal
init|=
name|qgetenv
argument_list|(
literal|"QT_QPA_FB_HIDECURSOR"
argument_list|)
decl_stmt|;
if|#
directive|if
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
name|bool
name|hideCursor
init|=
literal|false
decl_stmt|;
else|#
directive|else
name|bool
name|hideCursor
init|=
literal|true
decl_stmt|;
comment|// default to true to prevent the cursor showing up with the subclass on Android
endif|#
directive|endif
if|if
condition|(
name|hideCursorVal
operator|.
name|isEmpty
argument_list|()
condition|)
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
name|QScopedPointer
argument_list|<
name|QDeviceDiscovery
argument_list|>
name|dis
argument_list|(
name|QDeviceDiscovery
operator|::
name|create
argument_list|(
name|QDeviceDiscovery
operator|::
name|Device_Mouse
argument_list|)
argument_list|)
decl_stmt|;
name|hideCursor
operator|=
name|dis
operator|->
name|scanConnectedDevices
argument_list|()
operator|.
name|isEmpty
argument_list|()
expr_stmt|;
endif|#
directive|endif
block|}
else|else
block|{
name|hideCursor
operator|=
name|hideCursorVal
operator|.
name|toInt
argument_list|()
operator|!=
literal|0
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|hideCursor
condition|)
name|mCursor
operator|=
operator|new
name|QFbCursor
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|mTtyFd
operator|=
name|openTtyDevice
argument_list|(
name|ttyDevice
argument_list|)
expr_stmt|;
if|if
condition|(
name|mTtyFd
operator|==
operator|-
literal|1
condition|)
name|qWarning
argument_list|()
operator|<<
literal|"Failed to open tty"
operator|<<
name|strerror
argument_list|(
name|errno
argument_list|)
expr_stmt|;
if|if
condition|(
name|doSwitchToGraphicsMode
operator|&&
operator|!
name|switchToGraphicsMode
argument_list|(
name|mTtyFd
argument_list|,
operator|&
name|mOldTtyMode
argument_list|)
condition|)
name|qWarning
argument_list|()
operator|<<
literal|"Failed to set graphics mode"
operator|<<
name|strerror
argument_list|(
name|errno
argument_list|)
expr_stmt|;
name|blankScreen
argument_list|(
name|mFbFd
argument_list|,
literal|false
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|doRedraw
name|QRegion
name|QLinuxFbScreen
operator|::
name|doRedraw
parameter_list|()
block|{
name|QRegion
name|touched
init|=
name|QFbScreen
operator|::
name|doRedraw
argument_list|()
decl_stmt|;
if|if
condition|(
name|touched
operator|.
name|isEmpty
argument_list|()
condition|)
return|return
name|touched
return|;
if|if
condition|(
operator|!
name|mBlitter
condition|)
name|mBlitter
operator|=
operator|new
name|QPainter
argument_list|(
operator|&
name|mFbScreenImage
argument_list|)
expr_stmt|;
name|QVector
argument_list|<
name|QRect
argument_list|>
name|rects
init|=
name|touched
operator|.
name|rects
argument_list|()
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|rects
operator|.
name|size
argument_list|()
condition|;
name|i
operator|++
control|)
name|mBlitter
operator|->
name|drawImage
argument_list|(
name|rects
index|[
name|i
index|]
argument_list|,
operator|*
name|mScreenImage
argument_list|,
name|rects
index|[
name|i
index|]
argument_list|)
expr_stmt|;
return|return
name|touched
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
