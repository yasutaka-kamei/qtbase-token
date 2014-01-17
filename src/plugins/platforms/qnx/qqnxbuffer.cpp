begin_unit
begin_comment
comment|/*************************************************************************** ** ** Copyright (C) 2011 - 2012 Research In Motion ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qqnxglobal.h"
end_include
begin_include
include|#
directive|include
file|"qqnxbuffer.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/QDebug>
end_include
begin_include
include|#
directive|include
file|<errno.h>
end_include
begin_include
include|#
directive|include
file|<sys/mman.h>
end_include
begin_if
if|#
directive|if
name|defined
argument_list|(
name|QQNXBUFFER_DEBUG
argument_list|)
end_if
begin_define
DECL|macro|qBufferDebug
define|#
directive|define
name|qBufferDebug
value|qDebug
end_define
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|qBufferDebug
define|#
directive|define
name|qBufferDebug
value|QT_NO_QDEBUG_MACRO
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_constructor
DECL|function|QQnxBuffer
name|QQnxBuffer
operator|::
name|QQnxBuffer
parameter_list|()
member_init_list|:
name|m_buffer
argument_list|(
literal|0
argument_list|)
block|{
name|qBufferDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
operator|<<
literal|"empty"
expr_stmt|;
block|}
end_constructor
begin_constructor
DECL|function|QQnxBuffer
name|QQnxBuffer
operator|::
name|QQnxBuffer
parameter_list|(
name|screen_buffer_t
name|buffer
parameter_list|)
member_init_list|:
name|m_buffer
argument_list|(
name|buffer
argument_list|)
block|{
name|qBufferDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
operator|<<
literal|"normal"
expr_stmt|;
comment|// Get size of buffer
name|int
name|size
index|[
literal|2
index|]
decl_stmt|;
name|Q_SCREEN_CRITICALERROR
argument_list|(
name|screen_get_buffer_property_iv
argument_list|(
name|buffer
argument_list|,
name|SCREEN_PROPERTY_BUFFER_SIZE
argument_list|,
name|size
argument_list|)
argument_list|,
literal|"Failed to query buffer size"
argument_list|)
expr_stmt|;
comment|// Get stride of buffer
name|int
name|stride
decl_stmt|;
name|Q_SCREEN_CHECKERROR
argument_list|(
name|screen_get_buffer_property_iv
argument_list|(
name|buffer
argument_list|,
name|SCREEN_PROPERTY_STRIDE
argument_list|,
operator|&
name|stride
argument_list|)
argument_list|,
literal|"Failed to query buffer stride"
argument_list|)
expr_stmt|;
comment|// Get access to buffer's data
name|errno
operator|=
literal|0
expr_stmt|;
name|uchar
modifier|*
name|dataPtr
init|=
literal|0
decl_stmt|;
name|Q_SCREEN_CRITICALERROR
argument_list|(
name|screen_get_buffer_property_pv
argument_list|(
name|buffer
argument_list|,
name|SCREEN_PROPERTY_POINTER
argument_list|,
operator|(
name|void
operator|*
operator|*
operator|)
operator|&
name|dataPtr
argument_list|)
argument_list|,
literal|"Failed to query buffer pointer"
argument_list|)
expr_stmt|;
if|if
condition|(
name|dataPtr
operator|==
literal|0
condition|)
name|qFatal
argument_list|(
literal|"QQNX: buffer pointer is NULL, errno=%d"
argument_list|,
name|errno
argument_list|)
expr_stmt|;
comment|// Get format of buffer
name|int
name|screenFormat
decl_stmt|;
name|Q_SCREEN_CHECKERROR
argument_list|(
name|screen_get_buffer_property_iv
argument_list|(
name|buffer
argument_list|,
name|SCREEN_PROPERTY_FORMAT
argument_list|,
operator|&
name|screenFormat
argument_list|)
argument_list|,
literal|"Failed to query buffer format"
argument_list|)
expr_stmt|;
comment|// Convert screen format to QImage format
name|QImage
operator|::
name|Format
name|imageFormat
init|=
name|QImage
operator|::
name|Format_Invalid
decl_stmt|;
switch|switch
condition|(
name|screenFormat
condition|)
block|{
case|case
name|SCREEN_FORMAT_RGBX4444
case|:
name|imageFormat
operator|=
name|QImage
operator|::
name|Format_RGB444
expr_stmt|;
break|break;
case|case
name|SCREEN_FORMAT_RGBA4444
case|:
name|imageFormat
operator|=
name|QImage
operator|::
name|Format_ARGB4444_Premultiplied
expr_stmt|;
break|break;
case|case
name|SCREEN_FORMAT_RGBX5551
case|:
name|imageFormat
operator|=
name|QImage
operator|::
name|Format_RGB555
expr_stmt|;
break|break;
case|case
name|SCREEN_FORMAT_RGB565
case|:
name|imageFormat
operator|=
name|QImage
operator|::
name|Format_RGB16
expr_stmt|;
break|break;
case|case
name|SCREEN_FORMAT_RGBX8888
case|:
name|imageFormat
operator|=
name|QImage
operator|::
name|Format_RGB32
expr_stmt|;
break|break;
case|case
name|SCREEN_FORMAT_RGBA8888
case|:
name|imageFormat
operator|=
name|QImage
operator|::
name|Format_ARGB32_Premultiplied
expr_stmt|;
break|break;
default|default:
name|qFatal
argument_list|(
literal|"QQNX: unsupported buffer format, format=%d"
argument_list|,
name|screenFormat
argument_list|)
expr_stmt|;
block|}
comment|// wrap buffer in an image
name|m_image
operator|=
name|QImage
argument_list|(
name|dataPtr
argument_list|,
name|size
index|[
literal|0
index|]
argument_list|,
name|size
index|[
literal|1
index|]
argument_list|,
name|stride
argument_list|,
name|imageFormat
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_constructor
DECL|function|QQnxBuffer
name|QQnxBuffer
operator|::
name|QQnxBuffer
parameter_list|(
specifier|const
name|QQnxBuffer
modifier|&
name|other
parameter_list|)
member_init_list|:
name|m_buffer
argument_list|(
name|other
operator|.
name|m_buffer
argument_list|)
member_init_list|,
name|m_image
argument_list|(
name|other
operator|.
name|m_image
argument_list|)
block|{
name|qBufferDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
operator|<<
literal|"copy"
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QQnxBuffer
name|QQnxBuffer
operator|::
name|~
name|QQnxBuffer
parameter_list|()
block|{
name|qBufferDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|invalidateInCache
name|void
name|QQnxBuffer
operator|::
name|invalidateInCache
parameter_list|()
block|{
name|qBufferDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
expr_stmt|;
comment|// Verify native buffer exists
if|if
condition|(
name|m_buffer
operator|==
literal|0
condition|)
name|qFatal
argument_list|(
literal|"QQNX: can't invalidate cache for null buffer"
argument_list|)
expr_stmt|;
comment|// Evict buffer's data from cache
name|errno
operator|=
literal|0
expr_stmt|;
name|int
name|result
init|=
name|msync
argument_list|(
name|m_image
operator|.
name|bits
argument_list|()
argument_list|,
name|m_image
operator|.
name|height
argument_list|()
operator|*
name|m_image
operator|.
name|bytesPerLine
argument_list|()
argument_list|,
name|MS_INVALIDATE
operator||
name|MS_CACHE_ONLY
argument_list|)
decl_stmt|;
if|if
condition|(
name|result
operator|!=
literal|0
condition|)
name|qFatal
argument_list|(
literal|"QQNX: failed to invalidate cache, errno=%d"
argument_list|,
name|errno
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
