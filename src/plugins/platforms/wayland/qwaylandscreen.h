begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QWAYLANDSCREEN_H
end_ifndef
begin_define
DECL|macro|QWAYLANDSCREEN_H
define|#
directive|define
name|QWAYLANDSCREEN_H
end_define
begin_include
include|#
directive|include
file|<QtGui/QPlatformScreen>
end_include
begin_decl_stmt
DECL|variable|QWaylandDisplay
name|class
name|QWaylandDisplay
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QWaylandCursor
name|class
name|QWaylandCursor
decl_stmt|;
end_decl_stmt
begin_struct_decl
struct_decl|struct
name|wl_visual
struct_decl|;
end_struct_decl
begin_decl_stmt
name|class
name|QWaylandScreen
range|:
name|public
name|QPlatformScreen
block|{
name|public
operator|:
name|QWaylandScreen
argument_list|(
argument|QWaylandDisplay *waylandDisplay
argument_list|,
argument|struct wl_output *output
argument_list|,
argument|QRect geometry
argument_list|)
block|;
operator|~
name|QWaylandScreen
argument_list|()
block|;
name|QWaylandDisplay
operator|*
name|display
argument_list|()
specifier|const
block|;
name|QRect
name|geometry
argument_list|()
specifier|const
block|;
name|int
name|depth
argument_list|()
specifier|const
block|;
name|QImage
operator|::
name|Format
name|format
argument_list|()
specifier|const
block|;
name|wl_visual
operator|*
name|visual
argument_list|()
specifier|const
block|;
specifier|static
name|QWaylandScreen
operator|*
name|waylandScreenFromWindow
argument_list|(
name|QWindow
operator|*
name|window
argument_list|)
block|;
name|private
operator|:
name|QWaylandDisplay
operator|*
name|mWaylandDisplay
block|;     struct
name|wl_output
operator|*
name|mOutput
block|;
name|QRect
name|mGeometry
block|;
name|int
name|mDepth
block|;
name|QImage
operator|::
name|Format
name|mFormat
block|;
name|QSize
name|mPhysicalSize
block|;
name|QWaylandCursor
operator|*
name|mWaylandCursor
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QWAYLANDSCREEN_H
end_comment
end_unit
