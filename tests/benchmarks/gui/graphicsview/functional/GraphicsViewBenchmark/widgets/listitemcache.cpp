begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QGraphicsItem>
end_include
begin_include
include|#
directive|include
file|<QPainter>
end_include
begin_include
include|#
directive|include
file|<QDebug>
end_include
begin_include
include|#
directive|include
file|"listitemcache.h"
end_include
begin_constructor
DECL|function|ListItemCache
name|ListItemCache
operator|::
name|ListItemCache
parameter_list|()
block|{ }
end_constructor
begin_destructor
DECL|function|~ListItemCache
name|ListItemCache
operator|::
name|~
name|ListItemCache
parameter_list|()
block|{
name|QPixmapCache
operator|::
name|remove
argument_list|(
name|m_cacheKey
argument_list|)
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|draw
name|void
name|ListItemCache
operator|::
name|draw
parameter_list|(
name|QPainter
modifier|*
name|painter
parameter_list|)
block|{
name|QRectF
name|irect
init|=
name|sourceBoundingRect
argument_list|(
name|Qt
operator|::
name|LogicalCoordinates
argument_list|)
decl_stmt|;
name|QRectF
name|vrect
init|=
name|painter
operator|->
name|clipPath
argument_list|()
operator|.
name|boundingRect
argument_list|()
decl_stmt|;
if|if
condition|(
name|vrect
operator|.
name|intersects
argument_list|(
name|irect
argument_list|)
condition|)
block|{
name|QRectF
name|newVisibleRect
init|=
name|irect
operator|.
name|intersected
argument_list|(
name|vrect
argument_list|)
decl_stmt|;
name|QPixmap
name|pixmap
decl_stmt|;
if|if
condition|(
operator|!
name|QPixmapCache
operator|::
name|find
argument_list|(
name|m_cacheKey
argument_list|,
operator|&
name|pixmap
argument_list|)
operator|||
name|m_visibleRect
operator|.
name|toRect
argument_list|()
operator|!=
name|newVisibleRect
operator|.
name|toRect
argument_list|()
condition|)
block|{
comment|//qDebug()<< "ListItemCache: caching"<< m_visibleRect
comment|//<< "->"<< newVisibleRect;
name|pixmap
operator|=
name|QPixmap
argument_list|(
name|sourceBoundingRect
argument_list|()
operator|.
name|toRect
argument_list|()
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
name|pixmap
operator|.
name|fill
argument_list|(
name|Qt
operator|::
name|transparent
argument_list|)
expr_stmt|;
name|QPainter
name|pixmapPainter
argument_list|(
operator|&
name|pixmap
argument_list|)
decl_stmt|;
name|drawSource
argument_list|(
operator|&
name|pixmapPainter
argument_list|)
expr_stmt|;
name|pixmapPainter
operator|.
name|end
argument_list|()
expr_stmt|;
name|m_cacheKey
operator|=
name|QPixmapCache
operator|::
name|insert
argument_list|(
name|pixmap
argument_list|)
expr_stmt|;
name|m_visibleRect
operator|=
name|newVisibleRect
expr_stmt|;
block|}
comment|//qDebug()<< "ListItemCache: blitting"<< m_visibleRect;
name|painter
operator|->
name|drawPixmap
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|pixmap
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|sourceChanged
name|void
name|ListItemCache
operator|::
name|sourceChanged
parameter_list|(
name|ChangeFlags
parameter_list|)
block|{
name|QPixmapCache
operator|::
name|remove
argument_list|(
name|m_cacheKey
argument_list|)
expr_stmt|;
block|}
end_function
end_unit
