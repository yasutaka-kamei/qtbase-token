begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qshapedpixmapdndwindow_p.h"
end_include
begin_include
include|#
directive|include
file|<QtGui/QPainter>
end_include
begin_include
include|#
directive|include
file|<QtGui/QCursor>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_constructor
DECL|function|QShapedPixmapWindow
name|QShapedPixmapWindow
operator|::
name|QShapedPixmapWindow
parameter_list|()
member_init_list|:
name|QWindow
argument_list|()
member_init_list|,
name|m_backingStore
argument_list|(
literal|0
argument_list|)
block|{
name|QSurfaceFormat
name|format
decl_stmt|;
name|format
operator|.
name|setAlphaBufferSize
argument_list|(
literal|8
argument_list|)
expr_stmt|;
name|setFormat
argument_list|(
name|format
argument_list|)
expr_stmt|;
name|setSurfaceType
argument_list|(
name|RasterSurface
argument_list|)
expr_stmt|;
name|setFlags
argument_list|(
name|Qt
operator|::
name|ToolTip
operator||
name|Qt
operator|::
name|FramelessWindowHint
operator||
name|Qt
operator|::
name|X11BypassWindowManagerHint
operator||
name|Qt
operator|::
name|WindowTransparentForInput
argument_list|)
expr_stmt|;
name|create
argument_list|()
expr_stmt|;
name|m_backingStore
operator|=
operator|new
name|QBackingStore
argument_list|(
name|this
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QShapedPixmapWindow
name|QShapedPixmapWindow
operator|::
name|~
name|QShapedPixmapWindow
parameter_list|()
block|{
operator|delete
name|m_backingStore
expr_stmt|;
name|m_backingStore
operator|=
literal|0
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|render
name|void
name|QShapedPixmapWindow
operator|::
name|render
parameter_list|()
block|{
name|QRect
name|rect
argument_list|(
name|QPoint
argument_list|()
argument_list|,
name|geometry
argument_list|()
operator|.
name|size
argument_list|()
argument_list|)
decl_stmt|;
name|m_backingStore
operator|->
name|beginPaint
argument_list|(
name|rect
argument_list|)
expr_stmt|;
name|QPaintDevice
modifier|*
name|device
init|=
name|m_backingStore
operator|->
name|paintDevice
argument_list|()
decl_stmt|;
block|{
name|QPainter
name|p
argument_list|(
name|device
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
name|p
operator|.
name|drawPixmap
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|m_pixmap
argument_list|)
expr_stmt|;
block|}
name|m_backingStore
operator|->
name|endPaint
argument_list|()
expr_stmt|;
name|m_backingStore
operator|->
name|flush
argument_list|(
name|rect
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setPixmap
name|void
name|QShapedPixmapWindow
operator|::
name|setPixmap
parameter_list|(
specifier|const
name|QPixmap
modifier|&
name|pixmap
parameter_list|)
block|{
name|m_pixmap
operator|=
name|pixmap
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setHotspot
name|void
name|QShapedPixmapWindow
operator|::
name|setHotspot
parameter_list|(
specifier|const
name|QPoint
modifier|&
name|hotspot
parameter_list|)
block|{
name|m_hotSpot
operator|=
name|hotspot
expr_stmt|;
block|}
end_function
begin_function
DECL|function|updateGeometry
name|void
name|QShapedPixmapWindow
operator|::
name|updateGeometry
parameter_list|()
block|{
name|QRect
name|rect
argument_list|(
name|QCursor
operator|::
name|pos
argument_list|()
operator|-
name|m_hotSpot
argument_list|,
name|m_pixmap
operator|.
name|size
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|m_pixmap
operator|.
name|isNull
argument_list|()
condition|)
name|m_backingStore
operator|->
name|resize
argument_list|(
name|QSize
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|)
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|m_backingStore
operator|->
name|size
argument_list|()
operator|!=
name|m_pixmap
operator|.
name|size
argument_list|()
condition|)
name|m_backingStore
operator|->
name|resize
argument_list|(
name|m_pixmap
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
name|setGeometry
argument_list|(
name|rect
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|exposeEvent
name|void
name|QShapedPixmapWindow
operator|::
name|exposeEvent
parameter_list|(
name|QExposeEvent
modifier|*
parameter_list|)
block|{
name|render
argument_list|()
expr_stmt|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
