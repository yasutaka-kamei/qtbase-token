begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"webview.h"
end_include
begin_include
include|#
directive|include
file|"webview_p.h"
end_include
begin_include
include|#
directive|include
file|<QtGui>
end_include
begin_decl_stmt
DECL|variable|MotionEndWaitTime
specifier|static
specifier|const
name|int
name|MotionEndWaitTime
init|=
literal|2000
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|TileSideLength
specifier|static
specifier|const
name|int
name|TileSideLength
init|=
literal|128
decl_stmt|;
end_decl_stmt
begin_constructor
DECL|function|WebViewPrivate
name|WebViewPrivate
operator|::
name|WebViewPrivate
parameter_list|(
name|WebView
modifier|*
name|w
parameter_list|)
member_init_list|:
name|q
argument_list|(
name|w
argument_list|)
member_init_list|,
name|cache
argument_list|(
literal|0
argument_list|)
block|{
name|web
operator|=
operator|new
name|QGraphicsWebView
expr_stmt|;
name|web
operator|->
name|setParentItem
argument_list|(
name|q
operator|->
name|viewport
argument_list|()
argument_list|)
expr_stmt|;
name|web
operator|->
name|setSizePolicy
argument_list|(
name|QSizePolicy
operator|::
name|Expanding
argument_list|,
name|QSizePolicy
operator|::
name|Expanding
argument_list|)
expr_stmt|;
name|web
operator|->
name|page
argument_list|()
operator|->
name|mainFrame
argument_list|()
operator|->
name|setScrollBarPolicy
argument_list|(
name|Qt
operator|::
name|Horizontal
argument_list|,
name|Qt
operator|::
name|ScrollBarAlwaysOff
argument_list|)
expr_stmt|;
name|web
operator|->
name|page
argument_list|()
operator|->
name|mainFrame
argument_list|()
operator|->
name|setScrollBarPolicy
argument_list|(
name|Qt
operator|::
name|Vertical
argument_list|,
name|Qt
operator|::
name|ScrollBarAlwaysOff
argument_list|)
expr_stmt|;
name|web
operator|->
name|setZValue
argument_list|(
literal|3
argument_list|)
expr_stmt|;
comment|//    cache = new WebViewCache(web);
comment|//    web->setGraphicsEffect(cache);
name|adjustSize
argument_list|()
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|adjustSize
name|void
name|WebViewPrivate
operator|::
name|adjustSize
parameter_list|()
block|{
name|QSizeF
name|contentSize
init|=
name|web
operator|->
name|page
argument_list|()
operator|->
name|mainFrame
argument_list|()
operator|->
name|contentsSize
argument_list|()
decl_stmt|;
name|QPointF
name|pos
init|=
name|web
operator|->
name|pos
argument_list|()
decl_stmt|;
name|qreal
name|w
init|=
name|qMax
argument_list|(
name|contentSize
operator|.
name|width
argument_list|()
argument_list|,
name|q
operator|->
name|viewport
argument_list|()
operator|->
name|boundingRect
argument_list|()
operator|.
name|width
argument_list|()
argument_list|)
decl_stmt|;
name|qreal
name|h
init|=
name|qMax
argument_list|(
name|contentSize
operator|.
name|height
argument_list|()
argument_list|,
name|q
operator|->
name|viewport
argument_list|()
operator|->
name|boundingRect
argument_list|()
operator|.
name|height
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|web
operator|->
name|boundingRect
argument_list|()
operator|.
name|size
argument_list|()
operator|!=
name|QSizeF
argument_list|(
name|w
argument_list|,
name|h
argument_list|)
condition|)
block|{
comment|//qDebug()<< "WebView: adjustSize:"<< QSizeF(w, h);
name|web
operator|->
name|resize
argument_list|(
name|w
argument_list|,
name|h
argument_list|)
expr_stmt|;
name|web
operator|->
name|setPos
argument_list|(
name|pos
argument_list|)
expr_stmt|;
if|if
condition|(
name|w
operator|>
name|q
operator|->
name|viewport
argument_list|()
operator|->
name|boundingRect
argument_list|()
operator|.
name|width
argument_list|()
condition|)
name|q
operator|->
name|horizontalScrollBar
argument_list|()
operator|->
name|setSliderSize
argument_list|(
name|w
argument_list|)
expr_stmt|;
else|else
name|q
operator|->
name|horizontalScrollBar
argument_list|()
operator|->
name|setSliderSize
argument_list|(
literal|0.0
argument_list|)
expr_stmt|;
if|if
condition|(
name|h
operator|>
name|q
operator|->
name|viewport
argument_list|()
operator|->
name|boundingRect
argument_list|()
operator|.
name|height
argument_list|()
condition|)
name|q
operator|->
name|verticalScrollBar
argument_list|()
operator|->
name|setSliderSize
argument_list|(
name|h
argument_list|)
expr_stmt|;
else|else
name|q
operator|->
name|verticalScrollBar
argument_list|()
operator|->
name|setSliderSize
argument_list|(
literal|0.0
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|_q_loadStarted
name|void
name|WebViewPrivate
operator|::
name|_q_loadStarted
parameter_list|()
block|{
name|qDebug
argument_list|()
operator|<<
literal|"WebView: load started"
expr_stmt|;
name|adjustSize
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|_q_loadProgress
name|void
name|WebViewPrivate
operator|::
name|_q_loadProgress
parameter_list|(
name|int
name|progress
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
argument|progress
argument_list|)
comment|//    qDebug()<< "WebView: load progress"<< progress;
name|adjustSize
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|_q_loadFinished
name|void
name|WebViewPrivate
operator|::
name|_q_loadFinished
parameter_list|(
name|bool
name|ok
parameter_list|)
block|{
name|qDebug
argument_list|()
operator|<<
literal|"WebView: load finished"
operator|<<
operator|(
name|ok
condition|?
literal|"ok"
else|:
literal|"not ok"
operator|)
expr_stmt|;
name|adjustSize
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|_q_viewportChanged
name|void
name|WebViewPrivate
operator|::
name|_q_viewportChanged
parameter_list|(
name|QGraphicsWidget
modifier|*
name|viewport
parameter_list|)
block|{
name|web
operator|->
name|setParentItem
argument_list|(
name|viewport
argument_list|)
expr_stmt|;
name|viewport
operator|->
name|setFlag
argument_list|(
name|QGraphicsItem
operator|::
name|ItemClipsChildrenToShape
argument_list|,
literal|true
argument_list|)
expr_stmt|;
name|adjustSize
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|_q_motionEnded
name|void
name|WebViewPrivate
operator|::
name|_q_motionEnded
parameter_list|()
block|{
name|motionTimer
operator|.
name|stop
argument_list|()
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"Motion ended"
expr_stmt|;
name|q
operator|->
name|prepareGeometryChange
argument_list|()
expr_stmt|;
block|}
end_function
begin_constructor
DECL|function|WebViewCache
name|WebViewCache
operator|::
name|WebViewCache
parameter_list|(
name|QGraphicsWebView
modifier|*
name|webView
parameter_list|)
member_init_list|:
name|m_webView
argument_list|(
name|webView
argument_list|)
block|{     }
end_constructor
begin_destructor
DECL|function|~WebViewCache
name|WebViewCache
operator|::
name|~
name|WebViewCache
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|draw
name|void
name|WebViewCache
operator|::
name|draw
parameter_list|(
name|QPainter
modifier|*
name|painter
parameter_list|,
name|QGraphicsEffectSource
modifier|*
name|source
parameter_list|)
block|{
specifier|const
name|QGraphicsItem
modifier|*
name|item
init|=
name|source
operator|->
name|graphicsItem
argument_list|()
decl_stmt|;
name|QSizeF
name|itemSize
init|=
name|item
operator|->
name|boundingRect
argument_list|()
operator|.
name|size
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|qFuzzyCompare
argument_list|(
name|itemSize
operator|.
name|width
argument_list|()
argument_list|,
name|m_itemSize
operator|.
name|width
argument_list|()
argument_list|)
operator|||
operator|!
name|qFuzzyCompare
argument_list|(
name|itemSize
operator|.
name|height
argument_list|()
argument_list|,
name|m_itemSize
operator|.
name|height
argument_list|()
argument_list|)
condition|)
block|{
name|qDebug
argument_list|()
operator|<<
literal|"Refresh tile cache, for new size"
operator|<<
name|itemSize
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|m_tilePixmaps
operator|.
name|size
argument_list|()
condition|;
name|i
operator|++
control|)
block|{
name|QPixmapCache
operator|::
name|remove
argument_list|(
name|m_tilePixmaps
index|[
name|i
index|]
argument_list|)
expr_stmt|;
block|}
name|m_tilePixmaps
operator|.
name|clear
argument_list|()
expr_stmt|;
name|m_tileRects
operator|.
name|clear
argument_list|()
expr_stmt|;
name|int
name|itemWidth
init|=
name|itemSize
operator|.
name|width
argument_list|()
operator|+
literal|0.5
decl_stmt|;
name|int
name|itemHeight
init|=
name|itemSize
operator|.
name|height
argument_list|()
operator|+
literal|0.5
decl_stmt|;
name|int
name|tilesX
init|=
name|itemWidth
operator|/
name|TileSideLength
decl_stmt|;
name|int
name|tilesY
init|=
name|itemHeight
operator|/
name|TileSideLength
decl_stmt|;
if|if
condition|(
operator|(
name|itemWidth
operator|%
name|TileSideLength
operator|)
operator|!=
literal|0
condition|)
block|{
operator|++
name|tilesX
expr_stmt|;
block|}
if|if
condition|(
operator|(
name|itemHeight
operator|%
name|TileSideLength
operator|)
operator|!=
literal|0
condition|)
block|{
operator|++
name|tilesY
expr_stmt|;
block|}
name|int
name|tilesCount
init|=
name|tilesX
operator|*
name|tilesY
decl_stmt|;
name|m_tilePixmaps
operator|.
name|resize
argument_list|(
name|tilesCount
argument_list|)
expr_stmt|;
name|m_tileRects
operator|.
name|resize
argument_list|(
name|tilesCount
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|tilesX
condition|;
name|i
operator|++
control|)
block|{
for|for
control|(
name|int
name|j
init|=
literal|0
init|;
name|j
operator|<
name|tilesY
condition|;
name|j
operator|++
control|)
block|{
name|int
name|x
init|=
name|i
operator|*
name|TileSideLength
decl_stmt|;
name|int
name|y
init|=
name|j
operator|*
name|TileSideLength
decl_stmt|;
name|m_tileRects
index|[
name|i
operator|+
name|j
operator|*
name|tilesX
index|]
operator|=
name|QRectF
argument_list|(
name|x
argument_list|,
name|y
argument_list|,
name|TileSideLength
argument_list|,
name|TileSideLength
argument_list|)
expr_stmt|;
block|}
block|}
name|m_itemSize
operator|=
name|itemSize
expr_stmt|;
block|}
specifier|const
name|QGraphicsItem
modifier|*
name|parentItem
init|=
name|item
operator|->
name|parentItem
argument_list|()
decl_stmt|;
name|QPointF
name|itemPos
init|=
name|item
operator|->
name|pos
argument_list|()
decl_stmt|;
name|QRectF
name|parentRect
init|=
name|parentItem
operator|->
name|boundingRect
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
name|m_tileRects
operator|.
name|size
argument_list|()
condition|;
name|i
operator|++
control|)
block|{
name|QRectF
name|tileRect
init|=
name|m_tileRects
index|[
name|i
index|]
operator|.
name|translated
argument_list|(
name|itemPos
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|tileRect
operator|.
name|intersects
argument_list|(
name|parentRect
argument_list|)
operator|&&
operator|!
name|tileRect
operator|.
name|contains
argument_list|(
name|parentRect
argument_list|)
condition|)
block|{
continue|continue;
block|}
name|QPixmap
name|tilePixmap
decl_stmt|;
if|if
condition|(
operator|!
name|QPixmapCache
operator|::
name|find
argument_list|(
name|m_tilePixmaps
index|[
name|i
index|]
argument_list|,
operator|&
name|tilePixmap
argument_list|)
condition|)
block|{
name|tilePixmap
operator|=
name|QPixmap
argument_list|(
name|TileSideLength
argument_list|,
name|TileSideLength
argument_list|)
expr_stmt|;
name|QWebFrame
modifier|*
name|webFrame
init|=
name|m_webView
operator|->
name|page
argument_list|()
operator|->
name|mainFrame
argument_list|()
decl_stmt|;
name|QPainter
name|tilePainter
argument_list|(
operator|&
name|tilePixmap
argument_list|)
decl_stmt|;
name|tilePainter
operator|.
name|translate
argument_list|(
operator|-
name|m_tileRects
index|[
name|i
index|]
operator|.
name|left
argument_list|()
argument_list|,
operator|-
name|m_tileRects
index|[
name|i
index|]
operator|.
name|top
argument_list|()
argument_list|)
expr_stmt|;
name|webFrame
operator|->
name|render
argument_list|(
operator|&
name|tilePainter
argument_list|,
name|m_tileRects
index|[
name|i
index|]
operator|.
name|toRect
argument_list|()
argument_list|)
expr_stmt|;
name|tilePainter
operator|.
name|end
argument_list|()
expr_stmt|;
name|m_tilePixmaps
index|[
name|i
index|]
operator|=
name|QPixmapCache
operator|::
name|insert
argument_list|(
name|tilePixmap
argument_list|)
expr_stmt|;
block|}
name|tileRect
operator|=
name|tileRect
operator|.
name|translated
argument_list|(
operator|-
name|itemPos
argument_list|)
expr_stmt|;
name|painter
operator|->
name|drawPixmap
argument_list|(
name|tileRect
operator|.
name|topLeft
argument_list|()
argument_list|,
name|tilePixmap
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_constructor
DECL|function|WebView
name|WebView
operator|::
name|WebView
parameter_list|(
name|QGraphicsWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|AbstractScrollArea
argument_list|(
name|parent
argument_list|)
member_init_list|,
name|d
argument_list|(
operator|new
name|WebViewPrivate
argument_list|(
name|this
argument_list|)
argument_list|)
block|{
name|setSizePolicy
argument_list|(
name|QSizePolicy
operator|::
name|Expanding
argument_list|,
name|QSizePolicy
operator|::
name|Expanding
argument_list|)
expr_stmt|;
name|setContentsMargins
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|d
operator|->
name|web
operator|->
name|page
argument_list|()
argument_list|,
name|SIGNAL
argument_list|(
name|loadStarted
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|_q_loadStarted
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|d
operator|->
name|web
operator|->
name|page
argument_list|()
argument_list|,
name|SIGNAL
argument_list|(
name|loadProgress
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|_q_loadProgress
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|d
operator|->
name|web
operator|->
name|page
argument_list|()
argument_list|,
name|SIGNAL
argument_list|(
name|loadFinished
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|_q_loadFinished
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|this
argument_list|,
name|SIGNAL
argument_list|(
name|viewportChanged
argument_list|(
name|QGraphicsWidget
operator|*
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|_q_viewportChanged
argument_list|(
name|QGraphicsWidget
operator|*
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
operator|&
name|d
operator|->
name|motionTimer
argument_list|,
name|SIGNAL
argument_list|(
name|timeout
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|_q_motionEnded
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~WebView
name|WebView
operator|::
name|~
name|WebView
parameter_list|()
block|{
name|d
operator|->
name|web
operator|->
name|setGraphicsEffect
argument_list|(
literal|0
argument_list|)
expr_stmt|;
operator|delete
name|d
operator|->
name|cache
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|setUrl
name|void
name|WebView
operator|::
name|setUrl
parameter_list|(
specifier|const
name|QUrl
modifier|&
name|url
parameter_list|)
block|{
name|d
operator|->
name|adjustSize
argument_list|()
expr_stmt|;
name|d
operator|->
name|web
operator|->
name|setUrl
argument_list|(
name|url
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|scrollContentsBy
name|void
name|WebView
operator|::
name|scrollContentsBy
parameter_list|(
name|qreal
name|dx
parameter_list|,
name|qreal
name|dy
parameter_list|)
block|{
if|if
condition|(
name|qFuzzyCompare
argument_list|(
operator|(
name|float
operator|)
name|dy
argument_list|,
literal|0.0f
argument_list|)
operator|&&
name|qFuzzyCompare
argument_list|(
operator|(
name|float
operator|)
name|dx
argument_list|,
literal|0.0f
argument_list|)
condition|)
return|return;
if|if
condition|(
operator|!
name|d
operator|->
name|motionTimer
operator|.
name|isActive
argument_list|()
condition|)
block|{
name|d
operator|->
name|motionTimer
operator|.
name|start
argument_list|(
name|MotionEndWaitTime
argument_list|)
expr_stmt|;
block|}
name|QSizeF
name|contentSize
init|=
name|d
operator|->
name|web
operator|->
name|page
argument_list|()
operator|->
name|mainFrame
argument_list|()
operator|->
name|contentsSize
argument_list|()
decl_stmt|;
name|QRectF
name|viewportRect
init|=
name|viewport
argument_list|()
operator|->
name|boundingRect
argument_list|()
decl_stmt|;
name|QPointF
name|pos
init|=
name|d
operator|->
name|web
operator|->
name|pos
argument_list|()
decl_stmt|;
name|qreal
name|w
init|=
name|qMax
argument_list|(
name|contentSize
operator|.
name|width
argument_list|()
argument_list|,
name|viewportRect
operator|.
name|width
argument_list|()
argument_list|)
decl_stmt|;
name|qreal
name|h
init|=
name|qMax
argument_list|(
name|contentSize
operator|.
name|height
argument_list|()
argument_list|,
name|viewportRect
operator|.
name|height
argument_list|()
argument_list|)
decl_stmt|;
name|qreal
name|minx
init|=
name|qMin
argument_list|(
literal|0.0f
argument_list|,
operator|(
name|float
operator|)
operator|-
operator|(
name|w
operator|-
name|viewportRect
operator|.
name|width
argument_list|()
operator|)
argument_list|)
decl_stmt|;
name|qreal
name|miny
init|=
name|qMin
argument_list|(
literal|0.0f
argument_list|,
operator|(
name|float
operator|)
operator|-
operator|(
name|h
operator|-
name|viewportRect
operator|.
name|height
argument_list|()
operator|)
argument_list|)
decl_stmt|;
name|qreal
name|x
init|=
name|d
operator|->
name|web
operator|->
name|pos
argument_list|()
operator|.
name|x
argument_list|()
operator|-
name|dx
decl_stmt|;
if|if
condition|(
name|x
operator|<
name|minx
condition|)
name|x
operator|=
name|minx
expr_stmt|;
elseif|else
if|if
condition|(
name|x
operator|>
literal|0
condition|)
name|x
operator|=
literal|0.0
expr_stmt|;
name|qreal
name|y
init|=
name|d
operator|->
name|web
operator|->
name|pos
argument_list|()
operator|.
name|y
argument_list|()
operator|-
name|dy
decl_stmt|;
if|if
condition|(
name|y
operator|<
name|miny
condition|)
name|y
operator|=
name|miny
expr_stmt|;
elseif|else
if|if
condition|(
name|y
operator|>
literal|0
condition|)
name|y
operator|=
literal|0.0
expr_stmt|;
name|d
operator|->
name|web
operator|->
name|setPos
argument_list|(
name|x
argument_list|,
name|y
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|sizeHint
name|QSizeF
name|WebView
operator|::
name|sizeHint
parameter_list|(
name|Qt
operator|::
name|SizeHint
name|which
parameter_list|,
specifier|const
name|QSizeF
modifier|&
name|constraint
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|which
operator|==
name|Qt
operator|::
name|PreferredSize
condition|)
block|{
name|QSizeF
name|contentSize
init|=
name|d
operator|->
name|web
operator|->
name|page
argument_list|()
operator|->
name|mainFrame
argument_list|()
operator|->
name|contentsSize
argument_list|()
decl_stmt|;
return|return
name|contentSize
return|;
block|}
return|return
name|AbstractScrollArea
operator|::
name|sizeHint
argument_list|(
name|which
argument_list|,
name|constraint
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|resizeEvent
name|void
name|WebView
operator|::
name|resizeEvent
parameter_list|(
name|QGraphicsSceneResizeEvent
modifier|*
name|event
parameter_list|)
block|{
name|AbstractScrollArea
operator|::
name|resizeEvent
argument_list|(
name|event
argument_list|)
expr_stmt|;
name|d
operator|->
name|adjustSize
argument_list|()
expr_stmt|;
block|}
end_function
begin_include
include|#
directive|include
file|"moc_webview.cpp"
end_include
end_unit
