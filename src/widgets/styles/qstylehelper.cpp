begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<qstyleoption.h>
end_include
begin_include
include|#
directive|include
file|<qpainter.h>
end_include
begin_include
include|#
directive|include
file|<qpixmapcache.h>
end_include
begin_include
include|#
directive|include
file|<private/qmath_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qstyle_p.h>
end_include
begin_include
include|#
directive|include
file|<qmath.h>
end_include
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_WS_WIN
argument_list|)
end_if
begin_include
include|#
directive|include
file|"qt_windows.h"
end_include
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|Q_WS_MAC
argument_list|)
end_elif
begin_include
include|#
directive|include
file|<private/qt_cocoa_helpers_mac_p.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|"qstylehelper_p.h"
end_include
begin_include
include|#
directive|include
file|<qstringbuilder.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_namespace
DECL|namespace|QStyleHelper
namespace|namespace
name|QStyleHelper
block|{
DECL|function|uniqueName
name|QString
name|uniqueName
parameter_list|(
specifier|const
name|QString
modifier|&
name|key
parameter_list|,
specifier|const
name|QStyleOption
modifier|*
name|option
parameter_list|,
specifier|const
name|QSize
modifier|&
name|size
parameter_list|)
block|{
specifier|const
name|QStyleOptionComplex
modifier|*
name|complexOption
init|=
name|qstyleoption_cast
argument_list|<
specifier|const
name|QStyleOptionComplex
operator|*
argument_list|>
argument_list|(
name|option
argument_list|)
decl_stmt|;
name|QString
name|tmp
init|=
name|key
operator|%
name|HexString
argument_list|<
name|uint
argument_list|>
argument_list|(
name|option
operator|->
name|state
argument_list|)
operator|%
name|HexString
argument_list|<
name|uint
argument_list|>
argument_list|(
name|option
operator|->
name|direction
argument_list|)
operator|%
name|HexString
argument_list|<
name|uint
argument_list|>
argument_list|(
name|complexOption
condition|?
name|uint
argument_list|(
name|complexOption
operator|->
name|activeSubControls
argument_list|)
else|:
literal|0u
argument_list|)
operator|%
name|HexString
argument_list|<
name|quint64
argument_list|>
argument_list|(
name|option
operator|->
name|palette
operator|.
name|cacheKey
argument_list|()
argument_list|)
operator|%
name|HexString
argument_list|<
name|uint
argument_list|>
argument_list|(
name|size
operator|.
name|width
argument_list|()
argument_list|)
operator|%
name|HexString
argument_list|<
name|uint
argument_list|>
argument_list|(
name|size
operator|.
name|height
argument_list|()
argument_list|)
decl_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_SPINBOX
if|if
condition|(
specifier|const
name|QStyleOptionSpinBox
modifier|*
name|spinBox
init|=
name|qstyleoption_cast
argument_list|<
specifier|const
name|QStyleOptionSpinBox
operator|*
argument_list|>
argument_list|(
name|option
argument_list|)
condition|)
block|{
name|tmp
operator|=
name|tmp
operator|%
name|HexString
argument_list|<
name|uint
argument_list|>
argument_list|(
name|spinBox
operator|->
name|buttonSymbols
argument_list|)
operator|%
name|HexString
argument_list|<
name|uint
argument_list|>
argument_list|(
name|spinBox
operator|->
name|stepEnabled
argument_list|)
operator|%
name|QLatin1Char
argument_list|(
name|spinBox
operator|->
name|frame
condition|?
literal|'1'
else|:
literal|'0'
argument_list|)
expr_stmt|;
empty_stmt|;
block|}
endif|#
directive|endif
comment|// QT_NO_SPINBOX
return|return
name|tmp
return|;
block|}
DECL|function|dpiScaled
name|qreal
name|dpiScaled
parameter_list|(
name|qreal
name|value
parameter_list|)
block|{
specifier|static
name|qreal
name|scale
init|=
operator|-
literal|1
decl_stmt|;
if|if
condition|(
name|scale
operator|<
literal|0
condition|)
block|{
name|scale
operator|=
literal|1.0
expr_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|Q_WS_WIN
argument_list|)
block|{
name|HDC
name|hdcScreen
init|=
name|GetDC
argument_list|(
literal|0
argument_list|)
decl_stmt|;
name|int
name|dpi
init|=
name|GetDeviceCaps
argument_list|(
name|hdcScreen
argument_list|,
name|LOGPIXELSX
argument_list|)
decl_stmt|;
name|ReleaseDC
argument_list|(
literal|0
argument_list|,
name|hdcScreen
argument_list|)
expr_stmt|;
name|scale
operator|=
name|dpi
operator|/
literal|96.0
expr_stmt|;
block|}
elif|#
directive|elif
name|defined
argument_list|(
name|Q_WS_MAC
argument_list|)
name|scale
operator|=
name|qt_mac_get_scalefactor
argument_list|()
expr_stmt|;
endif|#
directive|endif
block|}
return|return
name|value
operator|*
name|scale
return|;
block|}
ifndef|#
directive|ifndef
name|QT_NO_DIAL
DECL|function|calcBigLineSize
name|int
name|calcBigLineSize
parameter_list|(
name|int
name|radius
parameter_list|)
block|{
name|int
name|bigLineSize
init|=
name|radius
operator|/
literal|6
decl_stmt|;
if|if
condition|(
name|bigLineSize
operator|<
literal|4
condition|)
name|bigLineSize
operator|=
literal|4
expr_stmt|;
if|if
condition|(
name|bigLineSize
operator|>
name|radius
operator|/
literal|2
condition|)
name|bigLineSize
operator|=
name|radius
operator|/
literal|2
expr_stmt|;
return|return
name|bigLineSize
return|;
block|}
DECL|function|calcRadialPos
specifier|static
name|QPointF
name|calcRadialPos
parameter_list|(
specifier|const
name|QStyleOptionSlider
modifier|*
name|dial
parameter_list|,
name|qreal
name|offset
parameter_list|)
block|{
specifier|const
name|int
name|width
init|=
name|dial
operator|->
name|rect
operator|.
name|width
argument_list|()
decl_stmt|;
specifier|const
name|int
name|height
init|=
name|dial
operator|->
name|rect
operator|.
name|height
argument_list|()
decl_stmt|;
specifier|const
name|int
name|r
init|=
name|qMin
argument_list|(
name|width
argument_list|,
name|height
argument_list|)
operator|/
literal|2
decl_stmt|;
specifier|const
name|int
name|currentSliderPosition
init|=
name|dial
operator|->
name|upsideDown
condition|?
name|dial
operator|->
name|sliderPosition
else|:
operator|(
name|dial
operator|->
name|maximum
operator|-
name|dial
operator|->
name|sliderPosition
operator|)
decl_stmt|;
name|qreal
name|a
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|dial
operator|->
name|maximum
operator|==
name|dial
operator|->
name|minimum
condition|)
name|a
operator|=
name|Q_PI
operator|/
literal|2
expr_stmt|;
elseif|else
if|if
condition|(
name|dial
operator|->
name|dialWrapping
condition|)
name|a
operator|=
name|Q_PI
operator|*
literal|3
operator|/
literal|2
operator|-
operator|(
name|currentSliderPosition
operator|-
name|dial
operator|->
name|minimum
operator|)
operator|*
literal|2
operator|*
name|Q_PI
operator|/
operator|(
name|dial
operator|->
name|maximum
operator|-
name|dial
operator|->
name|minimum
operator|)
expr_stmt|;
else|else
name|a
operator|=
operator|(
name|Q_PI
operator|*
literal|8
operator|-
operator|(
name|currentSliderPosition
operator|-
name|dial
operator|->
name|minimum
operator|)
operator|*
literal|10
operator|*
name|Q_PI
operator|/
operator|(
name|dial
operator|->
name|maximum
operator|-
name|dial
operator|->
name|minimum
operator|)
operator|)
operator|/
literal|6
expr_stmt|;
name|qreal
name|xc
init|=
name|width
operator|/
literal|2.0
decl_stmt|;
name|qreal
name|yc
init|=
name|height
operator|/
literal|2.0
decl_stmt|;
name|qreal
name|len
init|=
name|r
operator|-
name|QStyleHelper
operator|::
name|calcBigLineSize
argument_list|(
name|r
argument_list|)
operator|-
literal|3
decl_stmt|;
name|qreal
name|back
init|=
name|offset
operator|*
name|len
decl_stmt|;
name|QPointF
name|pos
argument_list|(
name|QPointF
argument_list|(
name|xc
operator|+
name|back
operator|*
name|qCos
argument_list|(
name|a
argument_list|)
argument_list|,
name|yc
operator|-
name|back
operator|*
name|qSin
argument_list|(
name|a
argument_list|)
argument_list|)
argument_list|)
decl_stmt|;
return|return
name|pos
return|;
block|}
DECL|function|angle
name|qreal
name|angle
parameter_list|(
specifier|const
name|QPointF
modifier|&
name|p1
parameter_list|,
specifier|const
name|QPointF
modifier|&
name|p2
parameter_list|)
block|{
specifier|static
specifier|const
name|qreal
name|rad_factor
init|=
literal|180
operator|/
name|Q_PI
decl_stmt|;
name|qreal
name|_angle
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|p1
operator|.
name|x
argument_list|()
operator|==
name|p2
operator|.
name|x
argument_list|()
condition|)
block|{
if|if
condition|(
name|p1
operator|.
name|y
argument_list|()
operator|<
name|p2
operator|.
name|y
argument_list|()
condition|)
name|_angle
operator|=
literal|270
expr_stmt|;
else|else
name|_angle
operator|=
literal|90
expr_stmt|;
block|}
else|else
block|{
name|qreal
name|x1
decl_stmt|,
name|x2
decl_stmt|,
name|y1
decl_stmt|,
name|y2
decl_stmt|;
if|if
condition|(
name|p1
operator|.
name|x
argument_list|()
operator|<=
name|p2
operator|.
name|x
argument_list|()
condition|)
block|{
name|x1
operator|=
name|p1
operator|.
name|x
argument_list|()
expr_stmt|;
name|y1
operator|=
name|p1
operator|.
name|y
argument_list|()
expr_stmt|;
name|x2
operator|=
name|p2
operator|.
name|x
argument_list|()
expr_stmt|;
name|y2
operator|=
name|p2
operator|.
name|y
argument_list|()
expr_stmt|;
block|}
else|else
block|{
name|x2
operator|=
name|p1
operator|.
name|x
argument_list|()
expr_stmt|;
name|y2
operator|=
name|p1
operator|.
name|y
argument_list|()
expr_stmt|;
name|x1
operator|=
name|p2
operator|.
name|x
argument_list|()
expr_stmt|;
name|y1
operator|=
name|p2
operator|.
name|y
argument_list|()
expr_stmt|;
block|}
name|qreal
name|m
init|=
operator|-
operator|(
name|y2
operator|-
name|y1
operator|)
operator|/
operator|(
name|x2
operator|-
name|x1
operator|)
decl_stmt|;
name|_angle
operator|=
name|qAtan
argument_list|(
name|m
argument_list|)
operator|*
name|rad_factor
expr_stmt|;
if|if
condition|(
name|p1
operator|.
name|x
argument_list|()
operator|<
name|p2
operator|.
name|x
argument_list|()
condition|)
name|_angle
operator|=
literal|180
operator|-
name|_angle
expr_stmt|;
else|else
name|_angle
operator|=
operator|-
name|_angle
expr_stmt|;
block|}
return|return
name|_angle
return|;
block|}
DECL|function|calcLines
name|QPolygonF
name|calcLines
parameter_list|(
specifier|const
name|QStyleOptionSlider
modifier|*
name|dial
parameter_list|)
block|{
name|QPolygonF
name|poly
decl_stmt|;
name|int
name|width
init|=
name|dial
operator|->
name|rect
operator|.
name|width
argument_list|()
decl_stmt|;
name|int
name|height
init|=
name|dial
operator|->
name|rect
operator|.
name|height
argument_list|()
decl_stmt|;
name|qreal
name|r
init|=
name|qMin
argument_list|(
name|width
argument_list|,
name|height
argument_list|)
operator|/
literal|2
decl_stmt|;
name|int
name|bigLineSize
init|=
name|calcBigLineSize
argument_list|(
name|int
argument_list|(
name|r
argument_list|)
argument_list|)
decl_stmt|;
name|qreal
name|xc
init|=
name|width
operator|/
literal|2
operator|+
literal|0.5
decl_stmt|;
name|qreal
name|yc
init|=
name|height
operator|/
literal|2
operator|+
literal|0.5
decl_stmt|;
name|int
name|ns
init|=
name|dial
operator|->
name|tickInterval
decl_stmt|;
name|int
name|notches
init|=
operator|(
name|dial
operator|->
name|maximum
operator|+
name|ns
operator|-
literal|1
operator|-
name|dial
operator|->
name|minimum
operator|)
operator|/
name|ns
decl_stmt|;
if|if
condition|(
name|notches
operator|<=
literal|0
condition|)
return|return
name|poly
return|;
if|if
condition|(
name|dial
operator|->
name|maximum
argument_list|<
name|dial
operator|->
name|minimum
operator|||
name|dial
operator|->
name|maximum
operator|-
name|dial
operator|->
name|minimum
argument_list|>
literal|1000
condition|)
block|{
name|int
name|maximum
init|=
name|dial
operator|->
name|minimum
operator|+
literal|1000
decl_stmt|;
name|notches
operator|=
operator|(
name|maximum
operator|+
name|ns
operator|-
literal|1
operator|-
name|dial
operator|->
name|minimum
operator|)
operator|/
name|ns
expr_stmt|;
block|}
name|poly
operator|.
name|resize
argument_list|(
literal|2
operator|+
literal|2
operator|*
name|notches
argument_list|)
expr_stmt|;
name|int
name|smallLineSize
init|=
name|bigLineSize
operator|/
literal|2
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<=
name|notches
condition|;
operator|++
name|i
control|)
block|{
name|qreal
name|angle
init|=
name|dial
operator|->
name|dialWrapping
condition|?
name|Q_PI
operator|*
literal|3
operator|/
literal|2
operator|-
name|i
operator|*
literal|2
operator|*
name|Q_PI
operator|/
name|notches
else|:
operator|(
name|Q_PI
operator|*
literal|8
operator|-
name|i
operator|*
literal|10
operator|*
name|Q_PI
operator|/
name|notches
operator|)
operator|/
literal|6
decl_stmt|;
name|qreal
name|s
init|=
name|qSin
argument_list|(
name|angle
argument_list|)
decl_stmt|;
name|qreal
name|c
init|=
name|qCos
argument_list|(
name|angle
argument_list|)
decl_stmt|;
if|if
condition|(
name|i
operator|==
literal|0
operator|||
operator|(
operator|(
operator|(
name|ns
operator|*
name|i
operator|)
operator|%
operator|(
name|dial
operator|->
name|pageStep
condition|?
name|dial
operator|->
name|pageStep
else|:
literal|1
operator|)
operator|)
operator|==
literal|0
operator|)
condition|)
block|{
name|poly
index|[
literal|2
operator|*
name|i
index|]
operator|=
name|QPointF
argument_list|(
name|xc
operator|+
operator|(
name|r
operator|-
name|bigLineSize
operator|)
operator|*
name|c
argument_list|,
name|yc
operator|-
operator|(
name|r
operator|-
name|bigLineSize
operator|)
operator|*
name|s
argument_list|)
expr_stmt|;
name|poly
index|[
literal|2
operator|*
name|i
operator|+
literal|1
index|]
operator|=
name|QPointF
argument_list|(
name|xc
operator|+
name|r
operator|*
name|c
argument_list|,
name|yc
operator|-
name|r
operator|*
name|s
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|poly
index|[
literal|2
operator|*
name|i
index|]
operator|=
name|QPointF
argument_list|(
name|xc
operator|+
operator|(
name|r
operator|-
literal|1
operator|-
name|smallLineSize
operator|)
operator|*
name|c
argument_list|,
name|yc
operator|-
operator|(
name|r
operator|-
literal|1
operator|-
name|smallLineSize
operator|)
operator|*
name|s
argument_list|)
expr_stmt|;
name|poly
index|[
literal|2
operator|*
name|i
operator|+
literal|1
index|]
operator|=
name|QPointF
argument_list|(
name|xc
operator|+
operator|(
name|r
operator|-
literal|1
operator|)
operator|*
name|c
argument_list|,
name|yc
operator|-
operator|(
name|r
operator|-
literal|1
operator|)
operator|*
name|s
argument_list|)
expr_stmt|;
block|}
block|}
return|return
name|poly
return|;
block|}
comment|// This will draw a nice and shiny QDial for us. We don't want
comment|// all the shinyness in QWindowsStyle, hence we place it here
DECL|function|drawDial
name|void
name|drawDial
parameter_list|(
specifier|const
name|QStyleOptionSlider
modifier|*
name|option
parameter_list|,
name|QPainter
modifier|*
name|painter
parameter_list|)
block|{
name|QPalette
name|pal
init|=
name|option
operator|->
name|palette
decl_stmt|;
name|QColor
name|buttonColor
init|=
name|pal
operator|.
name|button
argument_list|()
operator|.
name|color
argument_list|()
decl_stmt|;
specifier|const
name|int
name|width
init|=
name|option
operator|->
name|rect
operator|.
name|width
argument_list|()
decl_stmt|;
specifier|const
name|int
name|height
init|=
name|option
operator|->
name|rect
operator|.
name|height
argument_list|()
decl_stmt|;
specifier|const
name|bool
name|enabled
init|=
name|option
operator|->
name|state
operator|&
name|QStyle
operator|::
name|State_Enabled
decl_stmt|;
name|qreal
name|r
init|=
name|qMin
argument_list|(
name|width
argument_list|,
name|height
argument_list|)
operator|/
literal|2
decl_stmt|;
name|r
operator|-=
name|r
operator|/
literal|50
expr_stmt|;
specifier|const
name|qreal
name|penSize
init|=
name|r
operator|/
literal|20.0
decl_stmt|;
name|painter
operator|->
name|save
argument_list|()
expr_stmt|;
name|painter
operator|->
name|setRenderHint
argument_list|(
name|QPainter
operator|::
name|Antialiasing
argument_list|)
expr_stmt|;
comment|// Draw notches
if|if
condition|(
name|option
operator|->
name|subControls
operator|&
name|QStyle
operator|::
name|SC_DialTickmarks
condition|)
block|{
name|painter
operator|->
name|setPen
argument_list|(
name|option
operator|->
name|palette
operator|.
name|dark
argument_list|()
operator|.
name|color
argument_list|()
operator|.
name|darker
argument_list|(
literal|120
argument_list|)
argument_list|)
expr_stmt|;
name|painter
operator|->
name|drawLines
argument_list|(
name|QStyleHelper
operator|::
name|calcLines
argument_list|(
name|option
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|// Cache dial background
name|BEGIN_STYLE_PIXMAPCACHE
argument_list|(
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"qdial"
argument_list|)
argument_list|)
expr_stmt|;
name|p
operator|->
name|setRenderHint
argument_list|(
name|QPainter
operator|::
name|Antialiasing
argument_list|)
expr_stmt|;
specifier|const
name|qreal
name|d_
init|=
name|r
operator|/
literal|6
decl_stmt|;
specifier|const
name|qreal
name|dx
init|=
name|option
operator|->
name|rect
operator|.
name|x
argument_list|()
operator|+
name|d_
operator|+
operator|(
name|width
operator|-
literal|2
operator|*
name|r
operator|)
operator|/
literal|2
operator|+
literal|1
decl_stmt|;
specifier|const
name|qreal
name|dy
init|=
name|option
operator|->
name|rect
operator|.
name|y
argument_list|()
operator|+
name|d_
operator|+
operator|(
name|height
operator|-
literal|2
operator|*
name|r
operator|)
operator|/
literal|2
operator|+
literal|1
decl_stmt|;
name|QRectF
name|br
init|=
name|QRectF
argument_list|(
name|dx
operator|+
literal|0.5
argument_list|,
name|dy
operator|+
literal|0.5
argument_list|,
name|int
argument_list|(
name|r
operator|*
literal|2
operator|-
literal|2
operator|*
name|d_
operator|-
literal|2
argument_list|)
argument_list|,
name|int
argument_list|(
name|r
operator|*
literal|2
operator|-
literal|2
operator|*
name|d_
operator|-
literal|2
argument_list|)
argument_list|)
decl_stmt|;
name|buttonColor
operator|.
name|setHsv
argument_list|(
name|buttonColor
operator|.
name|hue
argument_list|()
argument_list|,
name|qMin
argument_list|(
literal|140
argument_list|,
name|buttonColor
operator|.
name|saturation
argument_list|()
argument_list|)
argument_list|,
name|qMax
argument_list|(
literal|180
argument_list|,
name|buttonColor
operator|.
name|value
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|QColor
name|shadowColor
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|20
argument_list|)
decl_stmt|;
if|if
condition|(
name|enabled
condition|)
block|{
comment|// Drop shadow
name|qreal
name|shadowSize
init|=
name|qMax
argument_list|(
literal|1.0
argument_list|,
name|penSize
operator|/
literal|2.0
argument_list|)
decl_stmt|;
name|QRectF
name|shadowRect
init|=
name|br
operator|.
name|adjusted
argument_list|(
operator|-
literal|2
operator|*
name|shadowSize
argument_list|,
operator|-
literal|2
operator|*
name|shadowSize
argument_list|,
literal|2
operator|*
name|shadowSize
argument_list|,
literal|2
operator|*
name|shadowSize
argument_list|)
decl_stmt|;
name|QRadialGradient
name|shadowGradient
argument_list|(
name|shadowRect
operator|.
name|center
argument_list|()
operator|.
name|x
argument_list|()
argument_list|,
name|shadowRect
operator|.
name|center
argument_list|()
operator|.
name|y
argument_list|()
argument_list|,
name|shadowRect
operator|.
name|width
argument_list|()
operator|/
literal|2.0
argument_list|,
name|shadowRect
operator|.
name|center
argument_list|()
operator|.
name|x
argument_list|()
argument_list|,
name|shadowRect
operator|.
name|center
argument_list|()
operator|.
name|y
argument_list|()
argument_list|)
decl_stmt|;
name|shadowGradient
operator|.
name|setColorAt
argument_list|(
name|qreal
argument_list|(
literal|0.91
argument_list|)
argument_list|,
name|QColor
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|40
argument_list|)
argument_list|)
expr_stmt|;
name|shadowGradient
operator|.
name|setColorAt
argument_list|(
name|qreal
argument_list|(
literal|1.0
argument_list|)
argument_list|,
name|Qt
operator|::
name|transparent
argument_list|)
expr_stmt|;
name|p
operator|->
name|setBrush
argument_list|(
name|shadowGradient
argument_list|)
expr_stmt|;
name|p
operator|->
name|setPen
argument_list|(
name|Qt
operator|::
name|NoPen
argument_list|)
expr_stmt|;
name|p
operator|->
name|translate
argument_list|(
name|shadowSize
argument_list|,
name|shadowSize
argument_list|)
expr_stmt|;
name|p
operator|->
name|drawEllipse
argument_list|(
name|shadowRect
argument_list|)
expr_stmt|;
name|p
operator|->
name|translate
argument_list|(
operator|-
name|shadowSize
argument_list|,
operator|-
name|shadowSize
argument_list|)
expr_stmt|;
comment|// Main gradient
name|QRadialGradient
name|gradient
argument_list|(
name|br
operator|.
name|center
argument_list|()
operator|.
name|x
argument_list|()
operator|-
name|br
operator|.
name|width
argument_list|()
operator|/
literal|3
argument_list|,
name|dy
argument_list|,
name|br
operator|.
name|width
argument_list|()
operator|*
literal|1.3
argument_list|,
name|br
operator|.
name|center
argument_list|()
operator|.
name|x
argument_list|()
argument_list|,
name|br
operator|.
name|center
argument_list|()
operator|.
name|y
argument_list|()
operator|-
name|br
operator|.
name|height
argument_list|()
operator|/
literal|2
argument_list|)
decl_stmt|;
name|gradient
operator|.
name|setColorAt
argument_list|(
literal|0
argument_list|,
name|buttonColor
operator|.
name|lighter
argument_list|(
literal|110
argument_list|)
argument_list|)
expr_stmt|;
name|gradient
operator|.
name|setColorAt
argument_list|(
name|qreal
argument_list|(
literal|0.5
argument_list|)
argument_list|,
name|buttonColor
argument_list|)
expr_stmt|;
name|gradient
operator|.
name|setColorAt
argument_list|(
name|qreal
argument_list|(
literal|0.501
argument_list|)
argument_list|,
name|buttonColor
operator|.
name|darker
argument_list|(
literal|102
argument_list|)
argument_list|)
expr_stmt|;
name|gradient
operator|.
name|setColorAt
argument_list|(
literal|1
argument_list|,
name|buttonColor
operator|.
name|darker
argument_list|(
literal|115
argument_list|)
argument_list|)
expr_stmt|;
name|p
operator|->
name|setBrush
argument_list|(
name|gradient
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|p
operator|->
name|setBrush
argument_list|(
name|Qt
operator|::
name|NoBrush
argument_list|)
expr_stmt|;
block|}
name|p
operator|->
name|setPen
argument_list|(
name|QPen
argument_list|(
name|buttonColor
operator|.
name|darker
argument_list|(
literal|280
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|p
operator|->
name|drawEllipse
argument_list|(
name|br
argument_list|)
expr_stmt|;
name|p
operator|->
name|setBrush
argument_list|(
name|Qt
operator|::
name|NoBrush
argument_list|)
expr_stmt|;
name|p
operator|->
name|setPen
argument_list|(
name|buttonColor
operator|.
name|lighter
argument_list|(
literal|110
argument_list|)
argument_list|)
expr_stmt|;
name|p
operator|->
name|drawEllipse
argument_list|(
name|br
operator|.
name|adjusted
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|,
operator|-
literal|1
argument_list|,
operator|-
literal|1
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|option
operator|->
name|state
operator|&
name|QStyle
operator|::
name|State_HasFocus
condition|)
block|{
name|QColor
name|highlight
init|=
name|pal
operator|.
name|highlight
argument_list|()
operator|.
name|color
argument_list|()
decl_stmt|;
name|highlight
operator|.
name|setHsv
argument_list|(
name|highlight
operator|.
name|hue
argument_list|()
argument_list|,
name|qMin
argument_list|(
literal|160
argument_list|,
name|highlight
operator|.
name|saturation
argument_list|()
argument_list|)
argument_list|,
name|qMax
argument_list|(
literal|230
argument_list|,
name|highlight
operator|.
name|value
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|highlight
operator|.
name|setAlpha
argument_list|(
literal|127
argument_list|)
expr_stmt|;
name|p
operator|->
name|setPen
argument_list|(
name|QPen
argument_list|(
name|highlight
argument_list|,
literal|2.0
argument_list|)
argument_list|)
expr_stmt|;
name|p
operator|->
name|setBrush
argument_list|(
name|Qt
operator|::
name|NoBrush
argument_list|)
expr_stmt|;
name|p
operator|->
name|drawEllipse
argument_list|(
name|br
operator|.
name|adjusted
argument_list|(
operator|-
literal|1
argument_list|,
operator|-
literal|1
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|END_STYLE_PIXMAPCACHE
name|QPointF
name|dp
init|=
name|calcRadialPos
argument_list|(
name|option
argument_list|,
name|qreal
argument_list|(
literal|0.70
argument_list|)
argument_list|)
decl_stmt|;
name|buttonColor
operator|=
name|buttonColor
operator|.
name|lighter
argument_list|(
literal|104
argument_list|)
expr_stmt|;
name|buttonColor
operator|.
name|setAlphaF
argument_list|(
name|qreal
argument_list|(
literal|0.8
argument_list|)
argument_list|)
expr_stmt|;
specifier|const
name|qreal
name|ds
init|=
name|r
operator|/
name|qreal
argument_list|(
literal|7.0
argument_list|)
decl_stmt|;
name|QRectF
name|dialRect
argument_list|(
name|dp
operator|.
name|x
argument_list|()
operator|-
name|ds
argument_list|,
name|dp
operator|.
name|y
argument_list|()
operator|-
name|ds
argument_list|,
literal|2
operator|*
name|ds
argument_list|,
literal|2
operator|*
name|ds
argument_list|)
decl_stmt|;
name|QRadialGradient
name|dialGradient
argument_list|(
name|dialRect
operator|.
name|center
argument_list|()
operator|.
name|x
argument_list|()
operator|+
name|dialRect
operator|.
name|width
argument_list|()
operator|/
literal|2
argument_list|,
name|dialRect
operator|.
name|center
argument_list|()
operator|.
name|y
argument_list|()
operator|+
name|dialRect
operator|.
name|width
argument_list|()
argument_list|,
name|dialRect
operator|.
name|width
argument_list|()
operator|*
literal|2
argument_list|,
name|dialRect
operator|.
name|center
argument_list|()
operator|.
name|x
argument_list|()
argument_list|,
name|dialRect
operator|.
name|center
argument_list|()
operator|.
name|y
argument_list|()
argument_list|)
decl_stmt|;
name|dialGradient
operator|.
name|setColorAt
argument_list|(
literal|1
argument_list|,
name|buttonColor
operator|.
name|darker
argument_list|(
literal|140
argument_list|)
argument_list|)
expr_stmt|;
name|dialGradient
operator|.
name|setColorAt
argument_list|(
name|qreal
argument_list|(
literal|0.4
argument_list|)
argument_list|,
name|buttonColor
operator|.
name|darker
argument_list|(
literal|120
argument_list|)
argument_list|)
expr_stmt|;
name|dialGradient
operator|.
name|setColorAt
argument_list|(
literal|0
argument_list|,
name|buttonColor
operator|.
name|darker
argument_list|(
literal|110
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|penSize
operator|>
literal|3.0
condition|)
block|{
name|painter
operator|->
name|setPen
argument_list|(
name|QPen
argument_list|(
name|QColor
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|25
argument_list|)
argument_list|,
name|penSize
argument_list|)
argument_list|)
expr_stmt|;
name|painter
operator|->
name|drawLine
argument_list|(
name|calcRadialPos
argument_list|(
name|option
argument_list|,
name|qreal
argument_list|(
literal|0.90
argument_list|)
argument_list|)
argument_list|,
name|calcRadialPos
argument_list|(
name|option
argument_list|,
name|qreal
argument_list|(
literal|0.96
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|painter
operator|->
name|setBrush
argument_list|(
name|dialGradient
argument_list|)
expr_stmt|;
name|painter
operator|->
name|setPen
argument_list|(
name|QColor
argument_list|(
literal|255
argument_list|,
literal|255
argument_list|,
literal|255
argument_list|,
literal|150
argument_list|)
argument_list|)
expr_stmt|;
name|painter
operator|->
name|drawEllipse
argument_list|(
name|dialRect
operator|.
name|adjusted
argument_list|(
operator|-
literal|1
argument_list|,
operator|-
literal|1
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
argument_list|)
expr_stmt|;
name|painter
operator|->
name|setPen
argument_list|(
name|QColor
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|80
argument_list|)
argument_list|)
expr_stmt|;
name|painter
operator|->
name|drawEllipse
argument_list|(
name|dialRect
argument_list|)
expr_stmt|;
name|painter
operator|->
name|restore
argument_list|()
expr_stmt|;
block|}
endif|#
directive|endif
comment|//QT_NO_DIAL
DECL|function|drawBorderPixmap
name|void
name|drawBorderPixmap
parameter_list|(
specifier|const
name|QPixmap
modifier|&
name|pixmap
parameter_list|,
name|QPainter
modifier|*
name|painter
parameter_list|,
specifier|const
name|QRect
modifier|&
name|rect
parameter_list|,
name|int
name|left
parameter_list|,
name|int
name|top
parameter_list|,
name|int
name|right
parameter_list|,
name|int
name|bottom
parameter_list|)
block|{
name|QSize
name|size
init|=
name|pixmap
operator|.
name|size
argument_list|()
decl_stmt|;
comment|//painter->setRenderHint(QPainter::SmoothPixmapTransform);
comment|//top
if|if
condition|(
name|top
operator|>
literal|0
condition|)
block|{
name|painter
operator|->
name|drawPixmap
argument_list|(
name|QRect
argument_list|(
name|rect
operator|.
name|left
argument_list|()
operator|+
name|left
argument_list|,
name|rect
operator|.
name|top
argument_list|()
argument_list|,
name|rect
operator|.
name|width
argument_list|()
operator|-
name|right
operator|-
name|left
argument_list|,
name|top
argument_list|)
argument_list|,
name|pixmap
argument_list|,
name|QRect
argument_list|(
name|left
argument_list|,
literal|0
argument_list|,
name|size
operator|.
name|width
argument_list|()
operator|-
name|right
operator|-
name|left
argument_list|,
name|top
argument_list|)
argument_list|)
expr_stmt|;
comment|//top-left
if|if
condition|(
name|left
operator|>
literal|0
condition|)
name|painter
operator|->
name|drawPixmap
argument_list|(
name|QRect
argument_list|(
name|rect
operator|.
name|left
argument_list|()
argument_list|,
name|rect
operator|.
name|top
argument_list|()
argument_list|,
name|left
argument_list|,
name|top
argument_list|)
argument_list|,
name|pixmap
argument_list|,
name|QRect
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|left
argument_list|,
name|top
argument_list|)
argument_list|)
expr_stmt|;
comment|//top-right
if|if
condition|(
name|right
operator|>
literal|0
condition|)
name|painter
operator|->
name|drawPixmap
argument_list|(
name|QRect
argument_list|(
name|rect
operator|.
name|left
argument_list|()
operator|+
name|rect
operator|.
name|width
argument_list|()
operator|-
name|right
argument_list|,
name|rect
operator|.
name|top
argument_list|()
argument_list|,
name|right
argument_list|,
name|top
argument_list|)
argument_list|,
name|pixmap
argument_list|,
name|QRect
argument_list|(
name|size
operator|.
name|width
argument_list|()
operator|-
name|right
argument_list|,
literal|0
argument_list|,
name|right
argument_list|,
name|top
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|//left
if|if
condition|(
name|left
operator|>
literal|0
condition|)
name|painter
operator|->
name|drawPixmap
argument_list|(
name|QRect
argument_list|(
name|rect
operator|.
name|left
argument_list|()
argument_list|,
name|rect
operator|.
name|top
argument_list|()
operator|+
name|top
argument_list|,
name|left
argument_list|,
name|rect
operator|.
name|height
argument_list|()
operator|-
name|top
operator|-
name|bottom
argument_list|)
argument_list|,
name|pixmap
argument_list|,
name|QRect
argument_list|(
literal|0
argument_list|,
name|top
argument_list|,
name|left
argument_list|,
name|size
operator|.
name|height
argument_list|()
operator|-
name|bottom
operator|-
name|top
argument_list|)
argument_list|)
expr_stmt|;
comment|//center
name|painter
operator|->
name|drawPixmap
argument_list|(
name|QRect
argument_list|(
name|rect
operator|.
name|left
argument_list|()
operator|+
name|left
argument_list|,
name|rect
operator|.
name|top
argument_list|()
operator|+
name|top
argument_list|,
name|rect
operator|.
name|width
argument_list|()
operator|-
name|right
operator|-
name|left
argument_list|,
name|rect
operator|.
name|height
argument_list|()
operator|-
name|bottom
operator|-
name|top
argument_list|)
argument_list|,
name|pixmap
argument_list|,
name|QRect
argument_list|(
name|left
argument_list|,
name|top
argument_list|,
name|size
operator|.
name|width
argument_list|()
operator|-
name|right
operator|-
name|left
argument_list|,
name|size
operator|.
name|height
argument_list|()
operator|-
name|bottom
operator|-
name|top
argument_list|)
argument_list|)
expr_stmt|;
comment|//right
if|if
condition|(
name|right
operator|>
literal|0
condition|)
name|painter
operator|->
name|drawPixmap
argument_list|(
name|QRect
argument_list|(
name|rect
operator|.
name|left
argument_list|()
operator|+
name|rect
operator|.
name|width
argument_list|()
operator|-
name|right
argument_list|,
name|rect
operator|.
name|top
argument_list|()
operator|+
name|top
argument_list|,
name|right
argument_list|,
name|rect
operator|.
name|height
argument_list|()
operator|-
name|top
operator|-
name|bottom
argument_list|)
argument_list|,
name|pixmap
argument_list|,
name|QRect
argument_list|(
name|size
operator|.
name|width
argument_list|()
operator|-
name|right
argument_list|,
name|top
argument_list|,
name|right
argument_list|,
name|size
operator|.
name|height
argument_list|()
operator|-
name|bottom
operator|-
name|top
argument_list|)
argument_list|)
expr_stmt|;
comment|//bottom
if|if
condition|(
name|bottom
operator|>
literal|0
condition|)
block|{
name|painter
operator|->
name|drawPixmap
argument_list|(
name|QRect
argument_list|(
name|rect
operator|.
name|left
argument_list|()
operator|+
name|left
argument_list|,
name|rect
operator|.
name|top
argument_list|()
operator|+
name|rect
operator|.
name|height
argument_list|()
operator|-
name|bottom
argument_list|,
name|rect
operator|.
name|width
argument_list|()
operator|-
name|right
operator|-
name|left
argument_list|,
name|bottom
argument_list|)
argument_list|,
name|pixmap
argument_list|,
name|QRect
argument_list|(
name|left
argument_list|,
name|size
operator|.
name|height
argument_list|()
operator|-
name|bottom
argument_list|,
name|size
operator|.
name|width
argument_list|()
operator|-
name|right
operator|-
name|left
argument_list|,
name|bottom
argument_list|)
argument_list|)
expr_stmt|;
comment|//bottom-left
if|if
condition|(
name|left
operator|>
literal|0
condition|)
name|painter
operator|->
name|drawPixmap
argument_list|(
name|QRect
argument_list|(
name|rect
operator|.
name|left
argument_list|()
argument_list|,
name|rect
operator|.
name|top
argument_list|()
operator|+
name|rect
operator|.
name|height
argument_list|()
operator|-
name|bottom
argument_list|,
name|left
argument_list|,
name|bottom
argument_list|)
argument_list|,
name|pixmap
argument_list|,
name|QRect
argument_list|(
literal|0
argument_list|,
name|size
operator|.
name|height
argument_list|()
operator|-
name|bottom
argument_list|,
name|left
argument_list|,
name|bottom
argument_list|)
argument_list|)
expr_stmt|;
comment|//bottom-right
if|if
condition|(
name|right
operator|>
literal|0
condition|)
name|painter
operator|->
name|drawPixmap
argument_list|(
name|QRect
argument_list|(
name|rect
operator|.
name|left
argument_list|()
operator|+
name|rect
operator|.
name|width
argument_list|()
operator|-
name|right
argument_list|,
name|rect
operator|.
name|top
argument_list|()
operator|+
name|rect
operator|.
name|height
argument_list|()
operator|-
name|bottom
argument_list|,
name|right
argument_list|,
name|bottom
argument_list|)
argument_list|,
name|pixmap
argument_list|,
name|QRect
argument_list|(
name|size
operator|.
name|width
argument_list|()
operator|-
name|right
argument_list|,
name|size
operator|.
name|height
argument_list|()
operator|-
name|bottom
argument_list|,
name|right
argument_list|,
name|bottom
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_namespace
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
