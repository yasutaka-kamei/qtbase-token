begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the demonstration applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtCore>
end_include
begin_include
include|#
directive|include
file|<QtWidgets>
end_include
begin_include
include|#
directive|include
file|<math.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|M_PI
end_ifndef
begin_define
DECL|macro|M_PI
define|#
directive|define
name|M_PI
value|3.14159265358979323846
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_define
DECL|macro|WORLD_SIZE
define|#
directive|define
name|WORLD_SIZE
value|8
end_define
begin_decl_stmt
DECL|variable|world_map
name|int
name|world_map
index|[
name|WORLD_SIZE
index|]
index|[
name|WORLD_SIZE
index|]
init|=
block|{
block|{
literal|1
block|,
literal|1
block|,
literal|1
block|,
literal|1
block|,
literal|6
block|,
literal|1
block|,
literal|1
block|,
literal|1
block|}
block|,
block|{
literal|1
block|,
literal|0
block|,
literal|0
block|,
literal|1
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|7
block|}
block|,
block|{
literal|1
block|,
literal|1
block|,
literal|0
block|,
literal|1
block|,
literal|0
block|,
literal|1
block|,
literal|1
block|,
literal|1
block|}
block|,
block|{
literal|6
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|3
block|}
block|,
block|{
literal|1
block|,
literal|8
block|,
literal|8
block|,
literal|0
block|,
literal|8
block|,
literal|0
block|,
literal|8
block|,
literal|1
block|}
block|,
block|{
literal|2
block|,
literal|2
block|,
literal|0
block|,
literal|0
block|,
literal|8
block|,
literal|8
block|,
literal|7
block|,
literal|1
block|}
block|,
block|{
literal|3
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|5
block|}
block|,
block|{
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|2
block|,
literal|7
block|,
literal|4
block|,
literal|4
block|,
literal|4
block|}
block|, }
decl_stmt|;
end_decl_stmt
begin_define
DECL|macro|TEXTURE_SIZE
define|#
directive|define
name|TEXTURE_SIZE
value|64
end_define
begin_define
DECL|macro|TEXTURE_BLOCK
define|#
directive|define
name|TEXTURE_BLOCK
value|(TEXTURE_SIZE * TEXTURE_SIZE)
end_define
begin_class
DECL|class|Raycasting
class|class
name|Raycasting
super|:
specifier|public
name|QWidget
block|{
public|public:
DECL|function|Raycasting
name|Raycasting
parameter_list|(
name|QWidget
modifier|*
name|parent
init|=
literal|0
parameter_list|)
member_init_list|:
name|QWidget
argument_list|(
name|parent
argument_list|)
member_init_list|,
name|angle
argument_list|(
literal|0.5
argument_list|)
member_init_list|,
name|playerPos
argument_list|(
literal|1.5
argument_list|,
literal|1.5
argument_list|)
member_init_list|,
name|angleDelta
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|moveDelta
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|touchDevice
argument_list|(
literal|false
argument_list|)
block|{
comment|// http://www.areyep.com/RIPandMCS-TextureLibrary.html
name|textureImg
operator|.
name|load
argument_list|(
literal|":/textures.png"
argument_list|)
expr_stmt|;
name|textureImg
operator|=
name|textureImg
operator|.
name|convertToFormat
argument_list|(
name|QImage
operator|::
name|Format_ARGB32
argument_list|)
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|textureImg
operator|.
name|width
argument_list|()
operator|==
name|TEXTURE_SIZE
operator|*
literal|2
argument_list|)
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|textureImg
operator|.
name|bytesPerLine
argument_list|()
operator|==
literal|4
operator|*
name|TEXTURE_SIZE
operator|*
literal|2
argument_list|)
expr_stmt|;
name|textureCount
operator|=
name|textureImg
operator|.
name|height
argument_list|()
operator|/
name|TEXTURE_SIZE
expr_stmt|;
name|watch
operator|.
name|start
argument_list|()
expr_stmt|;
name|ticker
operator|.
name|start
argument_list|(
literal|25
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|setAttribute
argument_list|(
name|Qt
operator|::
name|WA_OpaquePaintEvent
argument_list|,
literal|true
argument_list|)
expr_stmt|;
name|setMouseTracking
argument_list|(
literal|false
argument_list|)
expr_stmt|;
block|}
DECL|function|updatePlayer
name|void
name|updatePlayer
parameter_list|()
block|{
name|int
name|interval
init|=
name|qBound
argument_list|(
literal|20
argument_list|,
name|watch
operator|.
name|elapsed
argument_list|()
argument_list|,
literal|250
argument_list|)
decl_stmt|;
name|watch
operator|.
name|start
argument_list|()
expr_stmt|;
name|angle
operator|+=
name|angleDelta
operator|*
name|interval
operator|/
literal|1000
expr_stmt|;
name|qreal
name|step
init|=
name|moveDelta
operator|*
name|interval
operator|/
literal|1000
decl_stmt|;
name|qreal
name|dx
init|=
name|cos
argument_list|(
name|angle
argument_list|)
operator|*
name|step
decl_stmt|;
name|qreal
name|dy
init|=
name|sin
argument_list|(
name|angle
argument_list|)
operator|*
name|step
decl_stmt|;
name|QPointF
name|pos
init|=
name|playerPos
operator|+
literal|3
operator|*
name|QPointF
argument_list|(
name|dx
argument_list|,
name|dy
argument_list|)
decl_stmt|;
name|int
name|xi
init|=
cast|static_cast
argument_list|<
name|int
argument_list|>
argument_list|(
name|pos
operator|.
name|x
argument_list|()
argument_list|)
decl_stmt|;
name|int
name|yi
init|=
cast|static_cast
argument_list|<
name|int
argument_list|>
argument_list|(
name|pos
operator|.
name|y
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|world_map
index|[
name|yi
index|]
index|[
name|xi
index|]
operator|==
literal|0
condition|)
name|playerPos
operator|=
name|playerPos
operator|+
name|QPointF
argument_list|(
name|dx
argument_list|,
name|dy
argument_list|)
expr_stmt|;
block|}
DECL|function|showFps
name|void
name|showFps
parameter_list|()
block|{
specifier|static
name|QTime
name|frameTick
decl_stmt|;
specifier|static
name|int
name|totalFrame
init|=
literal|0
decl_stmt|;
if|if
condition|(
operator|!
operator|(
name|totalFrame
operator|&
literal|31
operator|)
condition|)
block|{
name|int
name|elapsed
init|=
name|frameTick
operator|.
name|elapsed
argument_list|()
decl_stmt|;
name|frameTick
operator|.
name|start
argument_list|()
expr_stmt|;
name|int
name|fps
init|=
literal|32
operator|*
literal|1000
operator|/
operator|(
literal|1
operator|+
name|elapsed
operator|)
decl_stmt|;
name|setWindowTitle
argument_list|(
name|QString
argument_list|(
literal|"Raycasting (%1 FPS)"
argument_list|)
operator|.
name|arg
argument_list|(
name|fps
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|totalFrame
operator|++
expr_stmt|;
block|}
DECL|function|render
name|void
name|render
parameter_list|()
block|{
comment|// setup the screen surface
if|if
condition|(
name|buffer
operator|.
name|size
argument_list|()
operator|!=
name|bufferSize
condition|)
name|buffer
operator|=
name|QImage
argument_list|(
name|bufferSize
argument_list|,
name|QImage
operator|::
name|Format_ARGB32
argument_list|)
expr_stmt|;
name|int
name|bufw
init|=
name|buffer
operator|.
name|width
argument_list|()
decl_stmt|;
name|int
name|bufh
init|=
name|buffer
operator|.
name|height
argument_list|()
decl_stmt|;
if|if
condition|(
name|bufw
operator|<=
literal|0
operator|||
name|bufh
operator|<=
literal|0
condition|)
return|return;
comment|// we intentionally cheat here, to avoid detach
specifier|const
name|uchar
modifier|*
name|ptr
init|=
name|buffer
operator|.
name|bits
argument_list|()
decl_stmt|;
name|QRgb
modifier|*
name|start
init|=
operator|(
name|QRgb
operator|*
operator|)
operator|(
name|ptr
operator|)
decl_stmt|;
name|QRgb
name|stride
init|=
name|buffer
operator|.
name|bytesPerLine
argument_list|()
operator|/
literal|4
decl_stmt|;
name|QRgb
modifier|*
name|finish
init|=
name|start
operator|+
name|stride
operator|*
name|bufh
decl_stmt|;
comment|// prepare the texture pointer
specifier|const
name|uchar
modifier|*
name|src
init|=
name|textureImg
operator|.
name|bits
argument_list|()
decl_stmt|;
specifier|const
name|QRgb
modifier|*
name|texsrc
init|=
cast|reinterpret_cast
argument_list|<
specifier|const
name|QRgb
operator|*
argument_list|>
argument_list|(
name|src
argument_list|)
decl_stmt|;
comment|// cast all rays here
name|qreal
name|sina
init|=
name|sin
argument_list|(
name|angle
argument_list|)
decl_stmt|;
name|qreal
name|cosa
init|=
name|cos
argument_list|(
name|angle
argument_list|)
decl_stmt|;
name|qreal
name|u
init|=
name|cosa
operator|-
name|sina
decl_stmt|;
name|qreal
name|v
init|=
name|sina
operator|+
name|cosa
decl_stmt|;
name|qreal
name|du
init|=
literal|2
operator|*
name|sina
operator|/
name|bufw
decl_stmt|;
name|qreal
name|dv
init|=
operator|-
literal|2
operator|*
name|cosa
operator|/
name|bufw
decl_stmt|;
for|for
control|(
name|int
name|ray
init|=
literal|0
init|;
name|ray
operator|<
name|bufw
condition|;
operator|++
name|ray
operator|,
name|u
operator|+=
name|du
operator|,
name|v
operator|+=
name|dv
control|)
block|{
comment|// every time this ray advances 'u' units in x direction,
comment|// it also advanced 'v' units in y direction
name|qreal
name|uu
init|=
operator|(
name|u
operator|<
literal|0
operator|)
condition|?
operator|-
name|u
else|:
name|u
decl_stmt|;
name|qreal
name|vv
init|=
operator|(
name|v
operator|<
literal|0
operator|)
condition|?
operator|-
name|v
else|:
name|v
decl_stmt|;
name|qreal
name|duu
init|=
literal|1
operator|/
name|uu
decl_stmt|;
name|qreal
name|dvv
init|=
literal|1
operator|/
name|vv
decl_stmt|;
name|int
name|stepx
init|=
operator|(
name|u
operator|<
literal|0
operator|)
condition|?
operator|-
literal|1
else|:
literal|1
decl_stmt|;
name|int
name|stepy
init|=
operator|(
name|v
operator|<
literal|0
operator|)
condition|?
operator|-
literal|1
else|:
literal|1
decl_stmt|;
comment|// the cell in the map that we need to check
name|qreal
name|px
init|=
name|playerPos
operator|.
name|x
argument_list|()
decl_stmt|;
name|qreal
name|py
init|=
name|playerPos
operator|.
name|y
argument_list|()
decl_stmt|;
name|int
name|mapx
init|=
cast|static_cast
argument_list|<
name|int
argument_list|>
argument_list|(
name|px
argument_list|)
decl_stmt|;
name|int
name|mapy
init|=
cast|static_cast
argument_list|<
name|int
argument_list|>
argument_list|(
name|py
argument_list|)
decl_stmt|;
comment|// the position and texture for the hit
name|int
name|texture
init|=
literal|0
decl_stmt|;
name|qreal
name|hitdist
init|=
literal|0.1
decl_stmt|;
name|qreal
name|texofs
init|=
literal|0
decl_stmt|;
name|bool
name|dark
init|=
literal|false
decl_stmt|;
comment|// first hit at constant x and constant y lines
name|qreal
name|distx
init|=
operator|(
name|u
operator|>
literal|0
operator|)
condition|?
operator|(
name|mapx
operator|+
literal|1
operator|-
name|px
operator|)
operator|*
name|duu
else|:
operator|(
name|px
operator|-
name|mapx
operator|)
operator|*
name|duu
decl_stmt|;
name|qreal
name|disty
init|=
operator|(
name|v
operator|>
literal|0
operator|)
condition|?
operator|(
name|mapy
operator|+
literal|1
operator|-
name|py
operator|)
operator|*
name|dvv
else|:
operator|(
name|py
operator|-
name|mapy
operator|)
operator|*
name|dvv
decl_stmt|;
comment|// loop until we hit something
while|while
condition|(
name|texture
operator|<=
literal|0
condition|)
block|{
if|if
condition|(
name|distx
operator|>
name|disty
condition|)
block|{
comment|// shorter distance to a hit in constant y line
name|hitdist
operator|=
name|disty
expr_stmt|;
name|disty
operator|+=
name|dvv
expr_stmt|;
name|mapy
operator|+=
name|stepy
expr_stmt|;
name|texture
operator|=
name|world_map
index|[
name|mapy
index|]
index|[
name|mapx
index|]
expr_stmt|;
if|if
condition|(
name|texture
operator|>
literal|0
condition|)
block|{
name|dark
operator|=
literal|true
expr_stmt|;
if|if
condition|(
name|stepy
operator|>
literal|0
condition|)
block|{
name|qreal
name|ofs
init|=
name|px
operator|+
name|u
operator|*
operator|(
name|mapy
operator|-
name|py
operator|)
operator|/
name|v
decl_stmt|;
name|texofs
operator|=
name|ofs
operator|-
name|floor
argument_list|(
name|ofs
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|qreal
name|ofs
init|=
name|px
operator|+
name|u
operator|*
operator|(
name|mapy
operator|+
literal|1
operator|-
name|py
operator|)
operator|/
name|v
decl_stmt|;
name|texofs
operator|=
name|ofs
operator|-
name|floor
argument_list|(
name|ofs
argument_list|)
expr_stmt|;
block|}
block|}
block|}
else|else
block|{
comment|// shorter distance to a hit in constant x line
name|hitdist
operator|=
name|distx
expr_stmt|;
name|distx
operator|+=
name|duu
expr_stmt|;
name|mapx
operator|+=
name|stepx
expr_stmt|;
name|texture
operator|=
name|world_map
index|[
name|mapy
index|]
index|[
name|mapx
index|]
expr_stmt|;
if|if
condition|(
name|texture
operator|>
literal|0
condition|)
block|{
if|if
condition|(
name|stepx
operator|>
literal|0
condition|)
block|{
name|qreal
name|ofs
init|=
name|py
operator|+
name|v
operator|*
operator|(
name|mapx
operator|-
name|px
operator|)
operator|/
name|u
decl_stmt|;
name|texofs
operator|=
name|ofs
operator|-
name|floor
argument_list|(
name|ofs
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|qreal
name|ofs
init|=
name|py
operator|+
name|v
operator|*
operator|(
name|mapx
operator|+
literal|1
operator|-
name|px
operator|)
operator|/
name|u
decl_stmt|;
name|texofs
operator|=
name|ceil
argument_list|(
name|ofs
argument_list|)
operator|-
name|ofs
expr_stmt|;
block|}
block|}
block|}
block|}
comment|// get the texture, note that the texture image
comment|// has two textures horizontally, "normal" vs "dark"
name|int
name|col
init|=
cast|static_cast
argument_list|<
name|int
argument_list|>
argument_list|(
name|texofs
operator|*
name|TEXTURE_SIZE
argument_list|)
decl_stmt|;
name|col
operator|=
name|qBound
argument_list|(
literal|0
argument_list|,
name|col
argument_list|,
name|TEXTURE_SIZE
operator|-
literal|1
argument_list|)
expr_stmt|;
name|texture
operator|=
operator|(
name|texture
operator|-
literal|1
operator|)
operator|%
name|textureCount
expr_stmt|;
specifier|const
name|QRgb
modifier|*
name|tex
init|=
name|texsrc
operator|+
name|TEXTURE_BLOCK
operator|*
name|texture
operator|*
literal|2
operator|+
operator|(
name|TEXTURE_SIZE
operator|*
literal|2
operator|*
name|col
operator|)
decl_stmt|;
if|if
condition|(
name|dark
condition|)
name|tex
operator|+=
name|TEXTURE_SIZE
expr_stmt|;
comment|// start from the texture center (horizontally)
name|int
name|h
init|=
cast|static_cast
argument_list|<
name|int
argument_list|>
argument_list|(
name|bufw
operator|/
name|hitdist
operator|/
literal|2
argument_list|)
decl_stmt|;
name|int
name|dy
init|=
operator|(
name|TEXTURE_SIZE
operator|<<
literal|12
operator|)
operator|/
name|h
decl_stmt|;
name|int
name|p1
init|=
operator|(
operator|(
name|TEXTURE_SIZE
operator|/
literal|2
operator|)
operator|<<
literal|12
operator|)
operator|-
name|dy
decl_stmt|;
name|int
name|p2
init|=
name|p1
operator|+
name|dy
decl_stmt|;
comment|// start from the screen center (vertically)
comment|// y1 will go up (decrease), y2 will go down (increase)
name|int
name|y1
init|=
name|bufh
operator|/
literal|2
decl_stmt|;
name|int
name|y2
init|=
name|y1
operator|+
literal|1
decl_stmt|;
name|QRgb
modifier|*
name|pixel1
init|=
name|start
operator|+
name|y1
operator|*
name|stride
operator|+
name|ray
decl_stmt|;
name|QRgb
modifier|*
name|pixel2
init|=
name|pixel1
operator|+
name|stride
decl_stmt|;
comment|// map the texture to the sliver
while|while
condition|(
name|y1
operator|>=
literal|0
operator|&&
name|y2
operator|<
name|bufh
operator|&&
name|p1
operator|>=
literal|0
condition|)
block|{
operator|*
name|pixel1
operator|=
name|tex
index|[
name|p1
operator|>>
literal|12
index|]
expr_stmt|;
operator|*
name|pixel2
operator|=
name|tex
index|[
name|p2
operator|>>
literal|12
index|]
expr_stmt|;
name|p1
operator|-=
name|dy
expr_stmt|;
name|p2
operator|+=
name|dy
expr_stmt|;
operator|--
name|y1
expr_stmt|;
operator|++
name|y2
expr_stmt|;
name|pixel1
operator|-=
name|stride
expr_stmt|;
name|pixel2
operator|+=
name|stride
expr_stmt|;
block|}
comment|// ceiling and floor
for|for
control|(
init|;
name|pixel1
operator|>
name|start
condition|;
name|pixel1
operator|-=
name|stride
control|)
operator|*
name|pixel1
operator|=
name|qRgb
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
for|for
control|(
init|;
name|pixel2
operator|<
name|finish
condition|;
name|pixel2
operator|+=
name|stride
control|)
operator|*
name|pixel2
operator|=
name|qRgb
argument_list|(
literal|96
argument_list|,
literal|96
argument_list|,
literal|96
argument_list|)
expr_stmt|;
block|}
name|update
argument_list|(
name|QRect
argument_list|(
name|QPoint
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|,
name|bufferSize
argument_list|)
argument_list|)
expr_stmt|;
block|}
protected|protected:
DECL|function|resizeEvent
name|void
name|resizeEvent
parameter_list|(
name|QResizeEvent
modifier|*
parameter_list|)
block|{
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WINCE_WM
argument_list|)
name|touchDevice
operator|=
literal|true
expr_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|Q_OS_SYMBIAN
argument_list|)
comment|// FIXME: use HAL
if|if
condition|(
name|width
argument_list|()
operator|>
literal|480
operator|||
name|height
argument_list|()
operator|>
literal|480
condition|)
name|touchDevice
operator|=
literal|true
expr_stmt|;
else|#
directive|else
name|touchDevice
operator|=
literal|false
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|touchDevice
condition|)
block|{
if|if
condition|(
name|width
argument_list|()
operator|<
name|height
argument_list|()
condition|)
block|{
name|trackPad
operator|=
name|QRect
argument_list|(
literal|0
argument_list|,
name|height
argument_list|()
operator|/
literal|2
argument_list|,
name|width
argument_list|()
argument_list|,
name|height
argument_list|()
operator|/
literal|2
argument_list|)
expr_stmt|;
name|centerPad
operator|=
name|QPoint
argument_list|(
name|width
argument_list|()
operator|/
literal|2
argument_list|,
name|height
argument_list|()
operator|*
literal|3
operator|/
literal|4
argument_list|)
expr_stmt|;
name|bufferSize
operator|=
name|QSize
argument_list|(
name|width
argument_list|()
argument_list|,
name|height
argument_list|()
operator|/
literal|2
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|trackPad
operator|=
name|QRect
argument_list|(
name|width
argument_list|()
operator|/
literal|2
argument_list|,
literal|0
argument_list|,
name|width
argument_list|()
operator|/
literal|2
argument_list|,
name|height
argument_list|()
argument_list|)
expr_stmt|;
name|centerPad
operator|=
name|QPoint
argument_list|(
name|width
argument_list|()
operator|*
literal|3
operator|/
literal|4
argument_list|,
name|height
argument_list|()
operator|/
literal|2
argument_list|)
expr_stmt|;
name|bufferSize
operator|=
name|QSize
argument_list|(
name|width
argument_list|()
operator|/
literal|2
argument_list|,
name|height
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|}
else|else
block|{
name|trackPad
operator|=
name|QRect
argument_list|()
expr_stmt|;
name|bufferSize
operator|=
name|size
argument_list|()
expr_stmt|;
block|}
name|update
argument_list|()
expr_stmt|;
block|}
DECL|function|timerEvent
name|void
name|timerEvent
parameter_list|(
name|QTimerEvent
modifier|*
parameter_list|)
block|{
name|updatePlayer
argument_list|()
expr_stmt|;
name|render
argument_list|()
expr_stmt|;
name|showFps
argument_list|()
expr_stmt|;
block|}
DECL|function|paintEvent
name|void
name|paintEvent
parameter_list|(
name|QPaintEvent
modifier|*
name|event
parameter_list|)
block|{
name|QPainter
name|p
argument_list|(
name|this
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
name|drawImage
argument_list|(
name|event
operator|->
name|rect
argument_list|()
argument_list|,
name|buffer
argument_list|,
name|event
operator|->
name|rect
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|touchDevice
operator|&&
name|event
operator|->
name|rect
argument_list|()
operator|.
name|intersects
argument_list|(
name|trackPad
argument_list|)
condition|)
block|{
name|p
operator|.
name|fillRect
argument_list|(
name|trackPad
argument_list|,
name|Qt
operator|::
name|white
argument_list|)
expr_stmt|;
name|p
operator|.
name|setPen
argument_list|(
name|QPen
argument_list|(
name|QColor
argument_list|(
literal|224
argument_list|,
literal|224
argument_list|,
literal|224
argument_list|)
argument_list|,
literal|6
argument_list|)
argument_list|)
expr_stmt|;
name|int
name|rad
init|=
name|qMin
argument_list|(
name|trackPad
operator|.
name|width
argument_list|()
argument_list|,
name|trackPad
operator|.
name|height
argument_list|()
argument_list|)
operator|*
literal|0.3
decl_stmt|;
name|p
operator|.
name|drawEllipse
argument_list|(
name|centerPad
argument_list|,
name|rad
argument_list|,
name|rad
argument_list|)
expr_stmt|;
name|p
operator|.
name|setPen
argument_list|(
name|Qt
operator|::
name|NoPen
argument_list|)
expr_stmt|;
name|p
operator|.
name|setBrush
argument_list|(
name|Qt
operator|::
name|gray
argument_list|)
expr_stmt|;
name|QPolygon
name|poly
decl_stmt|;
name|poly
operator|<<
name|QPoint
argument_list|(
operator|-
literal|30
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|poly
operator|<<
name|QPoint
argument_list|(
literal|0
argument_list|,
operator|-
literal|40
argument_list|)
expr_stmt|;
name|poly
operator|<<
name|QPoint
argument_list|(
literal|30
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|p
operator|.
name|translate
argument_list|(
name|centerPad
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
literal|4
condition|;
operator|++
name|i
control|)
block|{
name|p
operator|.
name|rotate
argument_list|(
literal|90
argument_list|)
expr_stmt|;
name|p
operator|.
name|translate
argument_list|(
literal|0
argument_list|,
literal|20
operator|-
name|rad
argument_list|)
expr_stmt|;
name|p
operator|.
name|drawPolygon
argument_list|(
name|poly
argument_list|)
expr_stmt|;
name|p
operator|.
name|translate
argument_list|(
literal|0
argument_list|,
name|rad
operator|-
literal|20
argument_list|)
expr_stmt|;
block|}
block|}
name|p
operator|.
name|end
argument_list|()
expr_stmt|;
block|}
DECL|function|keyPressEvent
name|void
name|keyPressEvent
parameter_list|(
name|QKeyEvent
modifier|*
name|event
parameter_list|)
block|{
name|event
operator|->
name|accept
argument_list|()
expr_stmt|;
if|if
condition|(
name|event
operator|->
name|key
argument_list|()
operator|==
name|Qt
operator|::
name|Key_Left
condition|)
name|angleDelta
operator|=
literal|1.3
operator|*
name|M_PI
expr_stmt|;
if|if
condition|(
name|event
operator|->
name|key
argument_list|()
operator|==
name|Qt
operator|::
name|Key_Right
condition|)
name|angleDelta
operator|=
operator|-
literal|1.3
operator|*
name|M_PI
expr_stmt|;
if|if
condition|(
name|event
operator|->
name|key
argument_list|()
operator|==
name|Qt
operator|::
name|Key_Up
condition|)
name|moveDelta
operator|=
literal|2.5
expr_stmt|;
if|if
condition|(
name|event
operator|->
name|key
argument_list|()
operator|==
name|Qt
operator|::
name|Key_Down
condition|)
name|moveDelta
operator|=
operator|-
literal|2.5
expr_stmt|;
block|}
DECL|function|keyReleaseEvent
name|void
name|keyReleaseEvent
parameter_list|(
name|QKeyEvent
modifier|*
name|event
parameter_list|)
block|{
name|event
operator|->
name|accept
argument_list|()
expr_stmt|;
if|if
condition|(
name|event
operator|->
name|key
argument_list|()
operator|==
name|Qt
operator|::
name|Key_Left
condition|)
name|angleDelta
operator|=
operator|(
name|angleDelta
operator|>
literal|0
operator|)
condition|?
literal|0
else|:
name|angleDelta
expr_stmt|;
if|if
condition|(
name|event
operator|->
name|key
argument_list|()
operator|==
name|Qt
operator|::
name|Key_Right
condition|)
name|angleDelta
operator|=
operator|(
name|angleDelta
operator|<
literal|0
operator|)
condition|?
literal|0
else|:
name|angleDelta
expr_stmt|;
if|if
condition|(
name|event
operator|->
name|key
argument_list|()
operator|==
name|Qt
operator|::
name|Key_Up
condition|)
name|moveDelta
operator|=
operator|(
name|moveDelta
operator|>
literal|0
operator|)
condition|?
literal|0
else|:
name|moveDelta
expr_stmt|;
if|if
condition|(
name|event
operator|->
name|key
argument_list|()
operator|==
name|Qt
operator|::
name|Key_Down
condition|)
name|moveDelta
operator|=
operator|(
name|moveDelta
operator|<
literal|0
operator|)
condition|?
literal|0
else|:
name|moveDelta
expr_stmt|;
block|}
DECL|function|mousePressEvent
name|void
name|mousePressEvent
parameter_list|(
name|QMouseEvent
modifier|*
name|event
parameter_list|)
block|{
name|qreal
name|dx
init|=
name|centerPad
operator|.
name|x
argument_list|()
operator|-
name|event
operator|->
name|pos
argument_list|()
operator|.
name|x
argument_list|()
decl_stmt|;
name|qreal
name|dy
init|=
name|centerPad
operator|.
name|y
argument_list|()
operator|-
name|event
operator|->
name|pos
argument_list|()
operator|.
name|y
argument_list|()
decl_stmt|;
name|angleDelta
operator|=
name|dx
operator|*
literal|2
operator|*
name|M_PI
operator|/
name|width
argument_list|()
expr_stmt|;
name|moveDelta
operator|=
name|dy
operator|*
literal|10
operator|/
name|height
argument_list|()
expr_stmt|;
block|}
DECL|function|mouseMoveEvent
name|void
name|mouseMoveEvent
parameter_list|(
name|QMouseEvent
modifier|*
name|event
parameter_list|)
block|{
name|qreal
name|dx
init|=
name|centerPad
operator|.
name|x
argument_list|()
operator|-
name|event
operator|->
name|pos
argument_list|()
operator|.
name|x
argument_list|()
decl_stmt|;
name|qreal
name|dy
init|=
name|centerPad
operator|.
name|y
argument_list|()
operator|-
name|event
operator|->
name|pos
argument_list|()
operator|.
name|y
argument_list|()
decl_stmt|;
name|angleDelta
operator|=
name|dx
operator|*
literal|2
operator|*
name|M_PI
operator|/
name|width
argument_list|()
expr_stmt|;
name|moveDelta
operator|=
name|dy
operator|*
literal|10
operator|/
name|height
argument_list|()
expr_stmt|;
block|}
DECL|function|mouseReleaseEvent
name|void
name|mouseReleaseEvent
parameter_list|(
name|QMouseEvent
modifier|*
parameter_list|)
block|{
name|angleDelta
operator|=
literal|0
expr_stmt|;
name|moveDelta
operator|=
literal|0
expr_stmt|;
block|}
private|private:
DECL|member|watch
name|QTime
name|watch
decl_stmt|;
DECL|member|ticker
name|QBasicTimer
name|ticker
decl_stmt|;
DECL|member|buffer
name|QImage
name|buffer
decl_stmt|;
DECL|member|angle
name|qreal
name|angle
decl_stmt|;
DECL|member|playerPos
name|QPointF
name|playerPos
decl_stmt|;
DECL|member|angleDelta
name|qreal
name|angleDelta
decl_stmt|;
DECL|member|moveDelta
name|qreal
name|moveDelta
decl_stmt|;
DECL|member|textureImg
name|QImage
name|textureImg
decl_stmt|;
DECL|member|textureCount
name|int
name|textureCount
decl_stmt|;
DECL|member|touchDevice
name|bool
name|touchDevice
decl_stmt|;
DECL|member|trackPad
name|QRect
name|trackPad
decl_stmt|;
DECL|member|centerPad
name|QPoint
name|centerPad
decl_stmt|;
DECL|member|bufferSize
name|QSize
name|bufferSize
decl_stmt|;
block|}
class|;
end_class
begin_function
DECL|function|main
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
block|{
name|QApplication
name|app
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
decl_stmt|;
name|Raycasting
name|w
decl_stmt|;
name|w
operator|.
name|setWindowTitle
argument_list|(
literal|"Raycasting"
argument_list|)
expr_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_SYMBIAN
argument_list|)
operator|||
name|defined
argument_list|(
name|Q_OS_WINCE_WM
argument_list|)
name|w
operator|.
name|showMaximized
argument_list|()
expr_stmt|;
else|#
directive|else
name|w
operator|.
name|resize
argument_list|(
literal|640
argument_list|,
literal|480
argument_list|)
expr_stmt|;
name|w
operator|.
name|show
argument_list|()
expr_stmt|;
endif|#
directive|endif
return|return
name|app
operator|.
name|exec
argument_list|()
return|;
block|}
end_function
end_unit
