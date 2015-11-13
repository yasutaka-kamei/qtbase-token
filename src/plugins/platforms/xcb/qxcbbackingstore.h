begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QXCBBACKINGSTORE_H
end_ifndef
begin_define
DECL|macro|QXCBBACKINGSTORE_H
define|#
directive|define
name|QXCBBACKINGSTORE_H
end_define
begin_include
include|#
directive|include
file|<qpa/qplatformbackingstore.h>
end_include
begin_include
include|#
directive|include
file|<xcb/xcb.h>
end_include
begin_include
include|#
directive|include
file|"qxcbobject.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QXcbShmImage
name|class
name|QXcbShmImage
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QXcbObject
name|class
name|QXcbBackingStore
range|:
name|public
name|QXcbObject
decl_stmt|,
name|public
name|QPlatformBackingStore
block|{
name|public
label|:
name|QXcbBackingStore
argument_list|(
name|QWindow
operator|*
name|widget
argument_list|)
expr_stmt|;
operator|~
name|QXcbBackingStore
argument_list|()
expr_stmt|;
name|QPaintDevice
operator|*
name|paintDevice
argument_list|()
name|Q_DECL_OVERRIDE
expr_stmt|;
name|void
name|flush
argument_list|(
name|QWindow
operator|*
name|window
argument_list|,
specifier|const
name|QRegion
operator|&
name|region
argument_list|,
specifier|const
name|QPoint
operator|&
name|offset
argument_list|)
name|Q_DECL_OVERRIDE
decl_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_OPENGL
name|void
name|composeAndFlush
argument_list|(
name|QWindow
operator|*
name|window
argument_list|,
specifier|const
name|QRegion
operator|&
name|region
argument_list|,
specifier|const
name|QPoint
operator|&
name|offset
argument_list|,
name|QPlatformTextureList
operator|*
name|textures
argument_list|,
name|QOpenGLContext
operator|*
name|context
argument_list|,
name|bool
name|translucentBackground
argument_list|)
name|Q_DECL_OVERRIDE
decl_stmt|;
name|QImage
name|toImage
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
expr_stmt|;
endif|#
directive|endif
name|QPlatformGraphicsBuffer
operator|*
name|graphicsBuffer
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
expr_stmt|;
name|void
name|resize
argument_list|(
specifier|const
name|QSize
operator|&
name|size
argument_list|,
specifier|const
name|QRegion
operator|&
name|staticContents
argument_list|)
name|Q_DECL_OVERRIDE
decl_stmt|;
name|bool
name|scroll
argument_list|(
specifier|const
name|QRegion
operator|&
name|area
argument_list|,
name|int
name|dx
argument_list|,
name|int
name|dy
argument_list|)
name|Q_DECL_OVERRIDE
decl_stmt|;
name|void
name|beginPaint
argument_list|(
specifier|const
name|QRegion
operator|&
argument_list|)
name|Q_DECL_OVERRIDE
decl_stmt|;
name|void
name|endPaint
argument_list|()
name|Q_DECL_OVERRIDE
expr_stmt|;
name|private
label|:
name|QXcbShmImage
modifier|*
name|m_image
decl_stmt|;
name|QRegion
name|m_paintRegion
decl_stmt|;
name|QImage
name|m_rgbImage
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
end_unit
