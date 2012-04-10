begin_unit
begin_comment
comment|/*************************************************************************** ** ** Copyright (C) 2011 - 2012 Research In Motion ** Contact: http://www.qt-project.org/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QQNXRASTERWINDOWSURFACE_H
end_ifndef
begin_define
DECL|macro|QQNXRASTERWINDOWSURFACE_H
define|#
directive|define
name|QQNXRASTERWINDOWSURFACE_H
end_define
begin_include
include|#
directive|include
file|<QtGui/qplatformbackingstore_qpa.h>
end_include
begin_include
include|#
directive|include
file|<screen/screen.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QQnxWindow
name|class
name|QQnxWindow
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QQnxRasterBackingStore
range|:
name|public
name|QPlatformBackingStore
block|{
name|public
operator|:
name|QQnxRasterBackingStore
argument_list|(
name|QWindow
operator|*
name|window
argument_list|)
block|;
operator|~
name|QQnxRasterBackingStore
argument_list|()
block|;
name|QPaintDevice
operator|*
name|paintDevice
argument_list|()
block|;
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
block|;
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
block|;
name|bool
name|scroll
argument_list|(
argument|const QRegion&area
argument_list|,
argument|int dx
argument_list|,
argument|int dy
argument_list|)
block|;
name|void
name|beginPaint
argument_list|(
specifier|const
name|QRegion
operator|&
name|region
argument_list|)
block|;
name|void
name|endPaint
argument_list|(
specifier|const
name|QRegion
operator|&
name|region
argument_list|)
block|;
name|private
operator|:
name|class
name|ScrollOp
block|{
name|public
operator|:
name|ScrollOp
argument_list|(
argument|const QRegion&a
argument_list|,
argument|int x
argument_list|,
argument|int y
argument_list|)
operator|:
name|totalArea
argument_list|(
name|a
argument_list|)
block|,
name|dx
argument_list|(
name|x
argument_list|)
block|,
name|dy
argument_list|(
argument|y
argument_list|)
block|{}
name|QRegion
name|totalArea
block|;
name|int
name|dx
block|;
name|int
name|dy
block|;     }
block|;
name|QQnxWindow
operator|*
name|m_platformWindow
block|;
name|QList
operator|<
name|ScrollOp
operator|>
name|m_scrollOpList
block|; }
decl_stmt|;
end_decl_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QQNXRASTERWINDOWSURFACE_H
end_comment
end_unit
