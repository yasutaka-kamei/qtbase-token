begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qxlibbackingstore.h"
end_include
begin_include
include|#
directive|include
file|"qxlibintegration.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/qdebug.h>
end_include
begin_include
include|#
directive|include
file|<QWindowSystemInterface>
end_include
begin_include
include|#
directive|include
file|"qxlibwindow.h"
end_include
begin_include
include|#
directive|include
file|"qxlibscreen.h"
end_include
begin_include
include|#
directive|include
file|"qxlibdisplay.h"
end_include
begin_include
include|#
directive|include
file|"qpainter.h"
end_include
begin_include
include|#
directive|include
file|<sys/ipc.h>
end_include
begin_include
include|#
directive|include
file|<sys/shm.h>
end_include
begin_include
include|#
directive|include
file|<X11/extensions/XShm.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_struct
DECL|struct|QXlibShmImageInfo
struct|struct
name|QXlibShmImageInfo
block|{
DECL|function|QXlibShmImageInfo
name|QXlibShmImageInfo
parameter_list|(
name|Display
modifier|*
name|xdisplay
parameter_list|)
member_init_list|:
name|image
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|display
argument_list|(
name|xdisplay
argument_list|)
block|{}
DECL|function|~QXlibShmImageInfo
name|~
name|QXlibShmImageInfo
parameter_list|()
block|{
name|destroy
argument_list|()
expr_stmt|;
block|}
name|void
name|destroy
parameter_list|()
function_decl|;
DECL|member|shminfo
name|XShmSegmentInfo
name|shminfo
decl_stmt|;
DECL|member|image
name|XImage
modifier|*
name|image
decl_stmt|;
DECL|member|display
name|Display
modifier|*
name|display
decl_stmt|;
block|}
struct|;
end_struct
begin_ifndef
ifndef|#
directive|ifndef
name|DONT_USE_MIT_SHM
end_ifndef
begin_function
DECL|function|destroy
name|void
name|QXlibShmImageInfo
operator|::
name|destroy
parameter_list|()
block|{
name|XShmDetach
argument_list|(
name|display
argument_list|,
operator|&
name|shminfo
argument_list|)
expr_stmt|;
name|XDestroyImage
argument_list|(
name|image
argument_list|)
expr_stmt|;
name|shmdt
argument_list|(
name|shminfo
operator|.
name|shmaddr
argument_list|)
expr_stmt|;
name|shmctl
argument_list|(
name|shminfo
operator|.
name|shmid
argument_list|,
name|IPC_RMID
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_function
DECL|function|resizeShmImage
name|void
name|QXlibBackingStore
operator|::
name|resizeShmImage
parameter_list|(
name|int
name|width
parameter_list|,
name|int
name|height
parameter_list|)
block|{
name|QXlibScreen
modifier|*
name|screen
init|=
name|QXlibScreen
operator|::
name|testLiteScreenForWidget
argument_list|(
name|window
argument_list|()
argument_list|)
decl_stmt|;
name|QXlibWindow
modifier|*
name|win
init|=
cast|static_cast
argument_list|<
name|QXlibWindow
operator|*
argument_list|>
argument_list|(
name|window
argument_list|()
operator|->
name|handle
argument_list|()
argument_list|)
decl_stmt|;
name|QImage
operator|::
name|Format
name|format
init|=
name|win
operator|->
name|depth
argument_list|()
operator|==
literal|16
condition|?
name|QImage
operator|::
name|Format_RGB16
else|:
name|QImage
operator|::
name|Format_RGB32
decl_stmt|;
ifdef|#
directive|ifdef
name|DONT_USE_MIT_SHM
name|shm_img
operator|=
name|QImage
argument_list|(
name|width
argument_list|,
name|height
argument_list|,
name|format
argument_list|)
expr_stmt|;
else|#
directive|else
if|if
condition|(
name|image_info
condition|)
name|image_info
operator|->
name|destroy
argument_list|()
expr_stmt|;
else|else
name|image_info
operator|=
operator|new
name|QXlibShmImageInfo
argument_list|(
name|screen
operator|->
name|display
argument_list|()
operator|->
name|nativeDisplay
argument_list|()
argument_list|)
expr_stmt|;
name|XImage
modifier|*
name|image
init|=
name|XShmCreateImage
argument_list|(
name|screen
operator|->
name|display
argument_list|()
operator|->
name|nativeDisplay
argument_list|()
argument_list|,
name|win
operator|->
name|visual
argument_list|()
argument_list|,
name|win
operator|->
name|depth
argument_list|()
argument_list|,
name|ZPixmap
argument_list|,
literal|0
argument_list|,
operator|&
name|image_info
operator|->
name|shminfo
argument_list|,
name|width
argument_list|,
name|height
argument_list|)
decl_stmt|;
name|image_info
operator|->
name|shminfo
operator|.
name|shmid
operator|=
name|shmget
argument_list|(
name|IPC_PRIVATE
argument_list|,
name|image
operator|->
name|bytes_per_line
operator|*
name|image
operator|->
name|height
argument_list|,
name|IPC_CREAT
operator||
literal|0777
argument_list|)
expr_stmt|;
name|image_info
operator|->
name|shminfo
operator|.
name|shmaddr
operator|=
name|image
operator|->
name|data
operator|=
operator|(
name|char
operator|*
operator|)
name|shmat
argument_list|(
name|image_info
operator|->
name|shminfo
operator|.
name|shmid
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|image_info
operator|->
name|shminfo
operator|.
name|readOnly
operator|=
name|False
expr_stmt|;
name|image_info
operator|->
name|image
operator|=
name|image
expr_stmt|;
name|Status
name|shm_attach_status
init|=
name|XShmAttach
argument_list|(
name|screen
operator|->
name|display
argument_list|()
operator|->
name|nativeDisplay
argument_list|()
argument_list|,
operator|&
name|image_info
operator|->
name|shminfo
argument_list|)
decl_stmt|;
name|Q_ASSERT
argument_list|(
name|shm_attach_status
operator|==
name|True
argument_list|)
expr_stmt|;
name|shm_img
operator|=
name|QImage
argument_list|(
operator|(
name|uchar
operator|*
operator|)
name|image
operator|->
name|data
argument_list|,
name|image
operator|->
name|width
argument_list|,
name|image
operator|->
name|height
argument_list|,
name|image
operator|->
name|bytes_per_line
argument_list|,
name|format
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|painted
operator|=
literal|false
expr_stmt|;
block|}
end_function
begin_function
DECL|function|resizeBuffer
name|void
name|QXlibBackingStore
operator|::
name|resizeBuffer
parameter_list|(
name|QSize
name|s
parameter_list|)
block|{
if|if
condition|(
name|shm_img
operator|.
name|size
argument_list|()
operator|!=
name|s
condition|)
name|resizeShmImage
argument_list|(
name|s
operator|.
name|width
argument_list|()
argument_list|,
name|s
operator|.
name|height
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|bufferSize
name|QSize
name|QXlibBackingStore
operator|::
name|bufferSize
parameter_list|()
specifier|const
block|{
return|return
name|shm_img
operator|.
name|size
argument_list|()
return|;
block|}
end_function
begin_constructor
DECL|function|QXlibBackingStore
name|QXlibBackingStore
operator|::
name|QXlibBackingStore
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|)
member_init_list|:
name|QPlatformBackingStore
argument_list|(
name|window
argument_list|)
member_init_list|,
name|painted
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|image_info
argument_list|(
literal|0
argument_list|)
block|{
name|xw
operator|=
cast|static_cast
argument_list|<
name|QXlibWindow
operator|*
argument_list|>
argument_list|(
name|window
operator|->
name|handle
argument_list|()
argument_list|)
expr_stmt|;
comment|//    qDebug()<< "QTestLiteWindowSurface::QTestLiteWindowSurface:"<< xw->window;
block|}
end_constructor
begin_destructor
DECL|function|~QXlibBackingStore
name|QXlibBackingStore
operator|::
name|~
name|QXlibBackingStore
parameter_list|()
block|{
operator|delete
name|image_info
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|paintDevice
name|QPaintDevice
modifier|*
name|QXlibBackingStore
operator|::
name|paintDevice
parameter_list|()
block|{
return|return
operator|&
name|shm_img
return|;
block|}
end_function
begin_function
DECL|function|flush
name|void
name|QXlibBackingStore
operator|::
name|flush
parameter_list|(
name|QWindow
modifier|*
name|w
parameter_list|,
specifier|const
name|QRegion
modifier|&
name|region
parameter_list|,
specifier|const
name|QPoint
modifier|&
name|offset
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|region
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|offset
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|painted
condition|)
return|return;
name|QXlibScreen
modifier|*
name|screen
init|=
name|QXlibScreen
operator|::
name|testLiteScreenForWidget
argument_list|(
name|w
argument_list|)
decl_stmt|;
name|GC
name|gc
init|=
name|xw
operator|->
name|graphicsContext
argument_list|()
decl_stmt|;
name|Window
name|window
init|=
name|xw
operator|->
name|xWindow
argument_list|()
decl_stmt|;
ifdef|#
directive|ifdef
name|DONT_USE_MIT_SHM
comment|// just convert the image every time...
if|if
condition|(
operator|!
name|shm_img
operator|.
name|isNull
argument_list|()
condition|)
block|{
name|QXlibWindow
modifier|*
name|win
init|=
cast|static_cast
argument_list|<
name|QXlibWindow
operator|*
argument_list|>
argument_list|(
name|w
operator|->
name|handle
argument_list|()
argument_list|)
decl_stmt|;
name|QImage
name|image
init|=
name|shm_img
decl_stmt|;
comment|//img.convertToFormat(
name|XImage
modifier|*
name|xi
init|=
name|XCreateImage
argument_list|(
name|screen
operator|->
name|display
argument_list|()
operator|->
name|nativeDisplay
argument_list|()
argument_list|,
name|win
operator|->
name|visual
argument_list|()
argument_list|,
name|win
operator|->
name|depth
argument_list|()
argument_list|,
name|ZPixmap
argument_list|,
literal|0
argument_list|,
operator|(
name|char
operator|*
operator|)
name|image
operator|.
name|scanLine
argument_list|(
literal|0
argument_list|)
argument_list|,
name|image
operator|.
name|width
argument_list|()
argument_list|,
name|image
operator|.
name|height
argument_list|()
argument_list|,
literal|32
argument_list|,
name|image
operator|.
name|bytesPerLine
argument_list|()
argument_list|)
decl_stmt|;
name|int
name|x
init|=
literal|0
decl_stmt|;
name|int
name|y
init|=
literal|0
decl_stmt|;
comment|/*int r =*/
name|XPutImage
argument_list|(
name|screen
operator|->
name|display
argument_list|()
operator|->
name|nativeDisplay
argument_list|()
argument_list|,
name|window
argument_list|,
name|gc
argument_list|,
name|xi
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
name|x
argument_list|,
name|y
argument_list|,
name|image
operator|.
name|width
argument_list|()
argument_list|,
name|image
operator|.
name|height
argument_list|()
argument_list|)
expr_stmt|;
name|xi
operator|->
name|data
operator|=
literal|0
expr_stmt|;
comment|// QImage owns these bits
name|XDestroyImage
argument_list|(
name|xi
argument_list|)
expr_stmt|;
block|}
else|#
directive|else
comment|// Use MIT_SHM
if|if
condition|(
name|image_info
operator|&&
name|image_info
operator|->
name|image
condition|)
block|{
comment|//qDebug()<< "Here we go"<< image_info->image->width<< image_info->image->height;
name|int
name|x
init|=
literal|0
decl_stmt|;
name|int
name|y
init|=
literal|0
decl_stmt|;
comment|// We could set send_event to true, and then use the ShmCompletion to synchronize,
comment|// but let's do like Qt/11 and just use XSync
name|XShmPutImage
argument_list|(
name|screen
operator|->
name|display
argument_list|()
operator|->
name|nativeDisplay
argument_list|()
argument_list|,
name|window
argument_list|,
name|gc
argument_list|,
name|image_info
operator|->
name|image
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
name|x
argument_list|,
name|y
argument_list|,
name|image_info
operator|->
name|image
operator|->
name|width
argument_list|,
name|image_info
operator|->
name|image
operator|->
name|height
argument_list|,
comment|/*send_event*/
name|False
argument_list|)
expr_stmt|;
name|screen
operator|->
name|display
argument_list|()
operator|->
name|sync
argument_list|()
expr_stmt|;
block|}
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|resize
name|void
name|QXlibBackingStore
operator|::
name|resize
parameter_list|(
specifier|const
name|QSize
modifier|&
name|size
parameter_list|,
specifier|const
name|QRegion
modifier|&
parameter_list|)
block|{
name|resizeBuffer
argument_list|(
name|size
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|beginPaint
name|void
name|QXlibBackingStore
operator|::
name|beginPaint
parameter_list|(
specifier|const
name|QRegion
modifier|&
name|region
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|region
argument_list|)
expr_stmt|;
if|if
condition|(
name|shm_img
operator|.
name|hasAlphaChannel
argument_list|()
condition|)
block|{
name|QPainter
name|p
argument_list|(
operator|&
name|shm_img
argument_list|)
decl_stmt|;
name|p
operator|.
name|setCompositionMode
argument_list|(
name|QPainter
operator|::
name|CompositionMode_Source
argument_list|)
expr_stmt|;
specifier|const
name|QVector
argument_list|<
name|QRect
argument_list|>
name|rects
init|=
name|region
operator|.
name|rects
argument_list|()
decl_stmt|;
specifier|const
name|QColor
name|blank
init|=
name|Qt
operator|::
name|transparent
decl_stmt|;
for|for
control|(
name|QVector
argument_list|<
name|QRect
argument_list|>
operator|::
name|const_iterator
name|it
init|=
name|rects
operator|.
name|begin
argument_list|()
init|;
name|it
operator|!=
name|rects
operator|.
name|end
argument_list|()
condition|;
operator|++
name|it
control|)
block|{
name|p
operator|.
name|fillRect
argument_list|(
operator|*
name|it
argument_list|,
name|blank
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_function
begin_function
DECL|function|endPaint
name|void
name|QXlibBackingStore
operator|::
name|endPaint
parameter_list|()
block|{
name|painted
operator|=
literal|true
expr_stmt|;
comment|//there is content in the buffer
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
