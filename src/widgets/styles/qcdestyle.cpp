begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qcdestyle.h"
end_include
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_STYLE_CDE
argument_list|)
operator|||
name|defined
argument_list|(
name|QT_PLUGIN
argument_list|)
end_if
begin_include
include|#
directive|include
file|"qmenu.h"
end_include
begin_include
include|#
directive|include
file|"qapplication.h"
end_include
begin_include
include|#
directive|include
file|"qpainter.h"
end_include
begin_include
include|#
directive|include
file|"qdrawutil.h"
end_include
begin_include
include|#
directive|include
file|"qpixmap.h"
end_include
begin_include
include|#
directive|include
file|"qpalette.h"
end_include
begin_include
include|#
directive|include
file|"qwidget.h"
end_include
begin_include
include|#
directive|include
file|"qpushbutton.h"
end_include
begin_include
include|#
directive|include
file|"qscrollbar.h"
end_include
begin_include
include|#
directive|include
file|"qtabbar.h"
end_include
begin_include
include|#
directive|include
file|"qtabwidget.h"
end_include
begin_include
include|#
directive|include
file|"qlistview.h"
end_include
begin_include
include|#
directive|include
file|"qsplitter.h"
end_include
begin_include
include|#
directive|include
file|"qslider.h"
end_include
begin_include
include|#
directive|include
file|"qcombobox.h"
end_include
begin_include
include|#
directive|include
file|"qlineedit.h"
end_include
begin_include
include|#
directive|include
file|"qprogressbar.h"
end_include
begin_include
include|#
directive|include
file|"qimage.h"
end_include
begin_include
include|#
directive|include
file|"qfocusframe.h"
end_include
begin_include
include|#
directive|include
file|"qpainterpath.h"
end_include
begin_include
include|#
directive|include
file|"qdebug.h"
end_include
begin_include
include|#
directive|include
file|<limits.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|/*!     \class QCDEStyle     \brief The QCDEStyle class provides a CDE look and feel.      \ingroup appearance     \inmodule QtWidgets      This style provides a slightly improved Motif look similar to some     versions of the Common Desktop Environment (CDE). The main     differences are thinner frames and more modern radio buttons and     checkboxes. Together with a dark background and a bright     text/foreground color, the style looks quite attractive (at least     for Motif fans).      Note that most of the functions provided by QCDEStyle are     reimplementations of QStyle functions; see QStyle for their     documentation. QCDEStyle provides overloads for drawControl() and     drawPrimitive() which are documented here.      \img qcdestyle.png     \sa QWindowsXPStyle, QMacStyle, QWindowsStyle, QPlastiqueStyle, QMotifStyle */
end_comment
begin_comment
comment|/*!     Constructs a QCDEStyle.      If \a useHighlightCols is false (the default), then the style will     polish the application's color palette to emulate the Motif way of     highlighting, which is a simple inversion between the base and the     text color. */
end_comment
begin_constructor
DECL|function|QCDEStyle
name|QCDEStyle
operator|::
name|QCDEStyle
parameter_list|(
name|bool
name|useHighlightCols
parameter_list|)
member_init_list|:
name|QMotifStyle
argument_list|(
name|useHighlightCols
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     Destroys the style. */
end_comment
begin_destructor
DECL|function|~QCDEStyle
name|QCDEStyle
operator|::
name|~
name|QCDEStyle
parameter_list|()
block|{ }
end_destructor
begin_comment
comment|/*!\reimp */
end_comment
begin_function
DECL|function|pixelMetric
name|int
name|QCDEStyle
operator|::
name|pixelMetric
parameter_list|(
name|PixelMetric
name|metric
parameter_list|,
specifier|const
name|QStyleOption
modifier|*
name|option
parameter_list|,
specifier|const
name|QWidget
modifier|*
name|widget
parameter_list|)
specifier|const
comment|/* int QCDEStyle::pixelMetric(PixelMetric metric, const QStyleOption *option,                            const QWidget *widget) const                            */
block|{
name|int
name|ret
init|=
literal|0
decl_stmt|;
switch|switch
condition|(
name|metric
condition|)
block|{
case|case
name|PM_MenuBarPanelWidth
case|:
case|case
name|PM_DefaultFrameWidth
case|:
case|case
name|PM_FocusFrameVMargin
case|:
case|case
name|PM_FocusFrameHMargin
case|:
case|case
name|PM_MenuPanelWidth
case|:
case|case
name|PM_SpinBoxFrameWidth
case|:
case|case
name|PM_MenuBarVMargin
case|:
case|case
name|PM_MenuBarHMargin
case|:
case|case
name|PM_DockWidgetFrameWidth
case|:
name|ret
operator|=
literal|1
expr_stmt|;
break|break;
case|case
name|PM_ScrollBarExtent
case|:
name|ret
operator|=
literal|13
expr_stmt|;
break|break;
default|default:
name|ret
operator|=
name|QMotifStyle
operator|::
name|pixelMetric
argument_list|(
name|metric
argument_list|,
name|option
argument_list|,
name|widget
argument_list|)
expr_stmt|;
break|break;
block|}
return|return
name|ret
return|;
block|}
end_function
begin_comment
comment|/*!     \reimp */
end_comment
begin_function
DECL|function|drawControl
name|void
name|QCDEStyle
operator|::
name|drawControl
parameter_list|(
name|ControlElement
name|element
parameter_list|,
specifier|const
name|QStyleOption
modifier|*
name|opt
parameter_list|,
name|QPainter
modifier|*
name|p
parameter_list|,
specifier|const
name|QWidget
modifier|*
name|widget
parameter_list|)
specifier|const
block|{
switch|switch
condition|(
name|element
condition|)
block|{
case|case
name|CE_MenuBarItem
case|:
block|{
if|if
condition|(
name|opt
operator|->
name|state
operator|&
name|State_Selected
condition|)
comment|// active item
name|qDrawShadePanel
argument_list|(
name|p
argument_list|,
name|opt
operator|->
name|rect
argument_list|,
name|opt
operator|->
name|palette
argument_list|,
literal|true
argument_list|,
literal|1
argument_list|,
operator|&
name|opt
operator|->
name|palette
operator|.
name|brush
argument_list|(
name|QPalette
operator|::
name|Button
argument_list|)
argument_list|)
expr_stmt|;
else|else
comment|// other item
name|p
operator|->
name|fillRect
argument_list|(
name|opt
operator|->
name|rect
argument_list|,
name|opt
operator|->
name|palette
operator|.
name|brush
argument_list|(
name|QPalette
operator|::
name|Button
argument_list|)
argument_list|)
expr_stmt|;
name|QCommonStyle
operator|::
name|drawControl
argument_list|(
name|element
argument_list|,
name|opt
argument_list|,
name|p
argument_list|,
name|widget
argument_list|)
expr_stmt|;
break|break;
block|}
case|case
name|CE_RubberBand
case|:
block|{
name|p
operator|->
name|save
argument_list|()
expr_stmt|;
name|p
operator|->
name|setClipping
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|QPainterPath
name|path
decl_stmt|;
name|path
operator|.
name|addRect
argument_list|(
name|opt
operator|->
name|rect
argument_list|)
expr_stmt|;
name|path
operator|.
name|addRect
argument_list|(
name|opt
operator|->
name|rect
operator|.
name|adjusted
argument_list|(
literal|2
argument_list|,
literal|2
argument_list|,
operator|-
literal|2
argument_list|,
operator|-
literal|2
argument_list|)
argument_list|)
expr_stmt|;
name|p
operator|->
name|fillPath
argument_list|(
name|path
argument_list|,
name|opt
operator|->
name|palette
operator|.
name|color
argument_list|(
name|QPalette
operator|::
name|Active
argument_list|,
name|QPalette
operator|::
name|Text
argument_list|)
argument_list|)
expr_stmt|;
name|p
operator|->
name|restore
argument_list|()
expr_stmt|;
break|break;
block|}
default|default:
name|QMotifStyle
operator|::
name|drawControl
argument_list|(
name|element
argument_list|,
name|opt
argument_list|,
name|p
argument_list|,
name|widget
argument_list|)
expr_stmt|;
break|break;
block|}
block|}
end_function
begin_comment
comment|/*!     \reimp */
end_comment
begin_function
DECL|function|drawPrimitive
name|void
name|QCDEStyle
operator|::
name|drawPrimitive
parameter_list|(
name|PrimitiveElement
name|pe
parameter_list|,
specifier|const
name|QStyleOption
modifier|*
name|opt
parameter_list|,
name|QPainter
modifier|*
name|p
parameter_list|,
specifier|const
name|QWidget
modifier|*
name|widget
parameter_list|)
specifier|const
block|{
switch|switch
condition|(
name|pe
condition|)
block|{
case|case
name|PE_IndicatorCheckBox
case|:
block|{
name|bool
name|down
init|=
name|opt
operator|->
name|state
operator|&
name|State_Sunken
decl_stmt|;
name|bool
name|on
init|=
name|opt
operator|->
name|state
operator|&
name|State_On
decl_stmt|;
name|bool
name|showUp
init|=
operator|!
operator|(
name|down
operator|^
name|on
operator|)
decl_stmt|;
name|QBrush
name|fill
init|=
operator|(
name|showUp
operator|||
operator|(
name|opt
operator|->
name|state
operator|&
name|State_NoChange
operator|)
operator|)
condition|?
name|opt
operator|->
name|palette
operator|.
name|brush
argument_list|(
name|QPalette
operator|::
name|Button
argument_list|)
else|:
name|opt
operator|->
name|palette
operator|.
name|brush
argument_list|(
name|QPalette
operator|::
name|Mid
argument_list|)
decl_stmt|;
name|qDrawShadePanel
argument_list|(
name|p
argument_list|,
name|opt
operator|->
name|rect
argument_list|,
name|opt
operator|->
name|palette
argument_list|,
operator|!
name|showUp
argument_list|,
name|pixelMetric
argument_list|(
name|PM_DefaultFrameWidth
argument_list|)
argument_list|,
operator|&
name|opt
operator|->
name|palette
operator|.
name|brush
argument_list|(
name|QPalette
operator|::
name|Button
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|on
operator|||
operator|(
name|opt
operator|->
name|state
operator|&
name|State_NoChange
operator|)
condition|)
block|{
name|QRect
name|r
init|=
name|opt
operator|->
name|rect
decl_stmt|;
name|QPolygon
name|a
argument_list|(
literal|7
operator|*
literal|2
argument_list|)
decl_stmt|;
name|int
name|i
decl_stmt|,
name|xx
decl_stmt|,
name|yy
decl_stmt|;
name|xx
operator|=
name|r
operator|.
name|x
argument_list|()
operator|+
literal|3
expr_stmt|;
name|yy
operator|=
name|r
operator|.
name|y
argument_list|()
operator|+
literal|5
expr_stmt|;
if|if
condition|(
name|opt
operator|->
name|rect
operator|.
name|width
argument_list|()
operator|<=
literal|9
condition|)
block|{
comment|// When called from CE_MenuItem in QMotifStyle
name|xx
operator|-=
literal|2
expr_stmt|;
name|yy
operator|-=
literal|2
expr_stmt|;
block|}
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
literal|3
condition|;
name|i
operator|++
control|)
block|{
name|a
operator|.
name|setPoint
argument_list|(
literal|2
operator|*
name|i
argument_list|,
name|xx
argument_list|,
name|yy
argument_list|)
expr_stmt|;
name|a
operator|.
name|setPoint
argument_list|(
literal|2
operator|*
name|i
operator|+
literal|1
argument_list|,
name|xx
argument_list|,
name|yy
operator|+
literal|2
argument_list|)
expr_stmt|;
name|xx
operator|++
expr_stmt|;
name|yy
operator|++
expr_stmt|;
block|}
name|yy
operator|-=
literal|2
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|3
init|;
name|i
operator|<
literal|7
condition|;
name|i
operator|++
control|)
block|{
name|a
operator|.
name|setPoint
argument_list|(
literal|2
operator|*
name|i
argument_list|,
name|xx
argument_list|,
name|yy
argument_list|)
expr_stmt|;
name|a
operator|.
name|setPoint
argument_list|(
literal|2
operator|*
name|i
operator|+
literal|1
argument_list|,
name|xx
argument_list|,
name|yy
operator|+
literal|2
argument_list|)
expr_stmt|;
name|xx
operator|++
expr_stmt|;
name|yy
operator|--
expr_stmt|;
block|}
if|if
condition|(
name|opt
operator|->
name|state
operator|&
name|State_NoChange
condition|)
name|p
operator|->
name|setPen
argument_list|(
name|opt
operator|->
name|palette
operator|.
name|dark
argument_list|()
operator|.
name|color
argument_list|()
argument_list|)
expr_stmt|;
else|else
name|p
operator|->
name|setPen
argument_list|(
name|opt
operator|->
name|palette
operator|.
name|foreground
argument_list|()
operator|.
name|color
argument_list|()
argument_list|)
expr_stmt|;
name|p
operator|->
name|drawPolyline
argument_list|(
name|a
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
operator|!
operator|(
name|opt
operator|->
name|state
operator|&
name|State_Enabled
operator|)
operator|&&
name|styleHint
argument_list|(
name|SH_DitherDisabledText
argument_list|)
condition|)
name|p
operator|->
name|fillRect
argument_list|(
name|opt
operator|->
name|rect
argument_list|,
name|QBrush
argument_list|(
name|p
operator|->
name|background
argument_list|()
operator|.
name|color
argument_list|()
argument_list|,
name|Qt
operator|::
name|Dense5Pattern
argument_list|)
argument_list|)
expr_stmt|;
block|}
break|break;
case|case
name|PE_IndicatorRadioButton
case|:
block|{
name|QRect
name|r
init|=
name|opt
operator|->
name|rect
decl_stmt|;
DECL|macro|INTARRLEN
define|#
directive|define
name|INTARRLEN
parameter_list|(
name|x
parameter_list|)
value|sizeof(x)/(sizeof(int)*2)
specifier|static
specifier|const
name|int
name|pts1
index|[]
init|=
block|{
comment|// up left  lines
literal|1
block|,
literal|9
block|,
literal|1
block|,
literal|8
block|,
literal|0
block|,
literal|7
block|,
literal|0
block|,
literal|4
block|,
literal|1
block|,
literal|3
block|,
literal|1
block|,
literal|2
block|,
literal|2
block|,
literal|1
block|,
literal|3
block|,
literal|1
block|,
literal|4
block|,
literal|0
block|,
literal|7
block|,
literal|0
block|,
literal|8
block|,
literal|1
block|,
literal|9
block|,
literal|1
block|}
decl_stmt|;
specifier|static
specifier|const
name|int
name|pts4
index|[]
init|=
block|{
comment|// bottom right  lines
literal|2
block|,
literal|10
block|,
literal|3
block|,
literal|10
block|,
literal|4
block|,
literal|11
block|,
literal|7
block|,
literal|11
block|,
literal|8
block|,
literal|10
block|,
literal|9
block|,
literal|10
block|,
literal|10
block|,
literal|9
block|,
literal|10
block|,
literal|8
block|,
literal|11
block|,
literal|7
block|,
literal|11
block|,
literal|4
block|,
literal|10
block|,
literal|3
block|,
literal|10
block|,
literal|2
block|}
decl_stmt|;
specifier|static
specifier|const
name|int
name|pts5
index|[]
init|=
block|{
comment|// inner fill
literal|4
block|,
literal|2
block|,
literal|7
block|,
literal|2
block|,
literal|9
block|,
literal|4
block|,
literal|9
block|,
literal|7
block|,
literal|7
block|,
literal|9
block|,
literal|4
block|,
literal|9
block|,
literal|2
block|,
literal|7
block|,
literal|2
block|,
literal|4
block|}
decl_stmt|;
name|bool
name|down
init|=
name|opt
operator|->
name|state
operator|&
name|State_Sunken
decl_stmt|;
name|bool
name|on
init|=
name|opt
operator|->
name|state
operator|&
name|State_On
decl_stmt|;
name|QPolygon
name|a
argument_list|(
name|INTARRLEN
argument_list|(
name|pts1
argument_list|)
argument_list|,
name|pts1
argument_list|)
decl_stmt|;
comment|//center when rect is larger than indicator size
name|int
name|xOffset
init|=
literal|0
decl_stmt|;
name|int
name|yOffset
init|=
literal|0
decl_stmt|;
name|int
name|indicatorWidth
init|=
name|pixelMetric
argument_list|(
name|PM_ExclusiveIndicatorWidth
argument_list|)
decl_stmt|;
name|int
name|indicatorHeight
init|=
name|pixelMetric
argument_list|(
name|PM_ExclusiveIndicatorWidth
argument_list|)
decl_stmt|;
if|if
condition|(
name|r
operator|.
name|width
argument_list|()
operator|>
name|indicatorWidth
condition|)
name|xOffset
operator|+=
operator|(
name|r
operator|.
name|width
argument_list|()
operator|-
name|indicatorWidth
operator|)
operator|/
literal|2
expr_stmt|;
if|if
condition|(
name|r
operator|.
name|height
argument_list|()
operator|>
name|indicatorHeight
condition|)
name|yOffset
operator|+=
operator|(
name|r
operator|.
name|height
argument_list|()
operator|-
name|indicatorHeight
operator|)
operator|/
literal|2
expr_stmt|;
name|p
operator|->
name|translate
argument_list|(
name|xOffset
argument_list|,
name|yOffset
argument_list|)
expr_stmt|;
name|a
operator|.
name|translate
argument_list|(
name|r
operator|.
name|x
argument_list|()
argument_list|,
name|r
operator|.
name|y
argument_list|()
argument_list|)
expr_stmt|;
name|QPen
name|oldPen
init|=
name|p
operator|->
name|pen
argument_list|()
decl_stmt|;
name|QBrush
name|oldBrush
init|=
name|p
operator|->
name|brush
argument_list|()
decl_stmt|;
name|p
operator|->
name|setPen
argument_list|(
operator|(
name|down
operator|||
name|on
operator|)
condition|?
name|opt
operator|->
name|palette
operator|.
name|dark
argument_list|()
operator|.
name|color
argument_list|()
else|:
name|opt
operator|->
name|palette
operator|.
name|light
argument_list|()
operator|.
name|color
argument_list|()
argument_list|)
expr_stmt|;
name|p
operator|->
name|drawPolyline
argument_list|(
name|a
argument_list|)
expr_stmt|;
name|a
operator|.
name|setPoints
argument_list|(
name|INTARRLEN
argument_list|(
name|pts4
argument_list|)
argument_list|,
name|pts4
argument_list|)
expr_stmt|;
name|a
operator|.
name|translate
argument_list|(
name|r
operator|.
name|x
argument_list|()
argument_list|,
name|r
operator|.
name|y
argument_list|()
argument_list|)
expr_stmt|;
name|p
operator|->
name|setPen
argument_list|(
operator|(
name|down
operator|||
name|on
operator|)
condition|?
name|opt
operator|->
name|palette
operator|.
name|light
argument_list|()
operator|.
name|color
argument_list|()
else|:
name|opt
operator|->
name|palette
operator|.
name|dark
argument_list|()
operator|.
name|color
argument_list|()
argument_list|)
expr_stmt|;
name|p
operator|->
name|drawPolyline
argument_list|(
name|a
argument_list|)
expr_stmt|;
name|a
operator|.
name|setPoints
argument_list|(
name|INTARRLEN
argument_list|(
name|pts5
argument_list|)
argument_list|,
name|pts5
argument_list|)
expr_stmt|;
name|a
operator|.
name|translate
argument_list|(
name|r
operator|.
name|x
argument_list|()
argument_list|,
name|r
operator|.
name|y
argument_list|()
argument_list|)
expr_stmt|;
name|QColor
name|fillColor
init|=
name|on
condition|?
name|opt
operator|->
name|palette
operator|.
name|dark
argument_list|()
operator|.
name|color
argument_list|()
else|:
name|opt
operator|->
name|palette
operator|.
name|background
argument_list|()
operator|.
name|color
argument_list|()
decl_stmt|;
name|p
operator|->
name|setPen
argument_list|(
name|fillColor
argument_list|)
expr_stmt|;
name|p
operator|->
name|setBrush
argument_list|(
name|on
condition|?
name|opt
operator|->
name|palette
operator|.
name|brush
argument_list|(
name|QPalette
operator|::
name|Dark
argument_list|)
else|:
name|opt
operator|->
name|palette
operator|.
name|brush
argument_list|(
name|QPalette
operator|::
name|Window
argument_list|)
argument_list|)
expr_stmt|;
name|p
operator|->
name|drawPolygon
argument_list|(
name|a
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
operator|(
name|opt
operator|->
name|state
operator|&
name|State_Enabled
operator|)
operator|&&
name|styleHint
argument_list|(
name|SH_DitherDisabledText
argument_list|)
condition|)
name|p
operator|->
name|fillRect
argument_list|(
name|opt
operator|->
name|rect
argument_list|,
name|QBrush
argument_list|(
name|p
operator|->
name|background
argument_list|()
operator|.
name|color
argument_list|()
argument_list|,
name|Qt
operator|::
name|Dense5Pattern
argument_list|)
argument_list|)
expr_stmt|;
name|p
operator|->
name|setPen
argument_list|(
name|oldPen
argument_list|)
expr_stmt|;
name|p
operator|->
name|setBrush
argument_list|(
name|oldBrush
argument_list|)
expr_stmt|;
name|p
operator|->
name|translate
argument_list|(
operator|-
name|xOffset
argument_list|,
operator|-
name|yOffset
argument_list|)
expr_stmt|;
block|}
break|break;
default|default:
name|QMotifStyle
operator|::
name|drawPrimitive
argument_list|(
name|pe
argument_list|,
name|opt
argument_list|,
name|p
argument_list|,
name|widget
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|/*!\reimp*/
end_comment
begin_function
DECL|function|standardPalette
name|QPalette
name|QCDEStyle
operator|::
name|standardPalette
parameter_list|()
specifier|const
block|{
name|QColor
name|background
argument_list|(
literal|0xb6
argument_list|,
literal|0xb6
argument_list|,
literal|0xcf
argument_list|)
decl_stmt|;
name|QColor
name|light
init|=
name|background
operator|.
name|lighter
argument_list|()
decl_stmt|;
name|QColor
name|mid
init|=
name|background
operator|.
name|darker
argument_list|(
literal|150
argument_list|)
decl_stmt|;
name|QColor
name|dark
init|=
name|background
operator|.
name|darker
argument_list|()
decl_stmt|;
name|QPalette
name|palette
argument_list|(
name|Qt
operator|::
name|black
argument_list|,
name|background
argument_list|,
name|light
argument_list|,
name|dark
argument_list|,
name|mid
argument_list|,
name|Qt
operator|::
name|black
argument_list|,
name|Qt
operator|::
name|white
argument_list|)
decl_stmt|;
name|palette
operator|.
name|setBrush
argument_list|(
name|QPalette
operator|::
name|Disabled
argument_list|,
name|QPalette
operator|::
name|WindowText
argument_list|,
name|dark
argument_list|)
expr_stmt|;
name|palette
operator|.
name|setBrush
argument_list|(
name|QPalette
operator|::
name|Disabled
argument_list|,
name|QPalette
operator|::
name|Text
argument_list|,
name|dark
argument_list|)
expr_stmt|;
name|palette
operator|.
name|setBrush
argument_list|(
name|QPalette
operator|::
name|Disabled
argument_list|,
name|QPalette
operator|::
name|ButtonText
argument_list|,
name|dark
argument_list|)
expr_stmt|;
name|palette
operator|.
name|setBrush
argument_list|(
name|QPalette
operator|::
name|Disabled
argument_list|,
name|QPalette
operator|::
name|Base
argument_list|,
name|background
argument_list|)
expr_stmt|;
return|return
name|palette
return|;
block|}
end_function
begin_comment
comment|/*!     \internal */
end_comment
begin_function
DECL|function|standardIconImplementation
name|QIcon
name|QCDEStyle
operator|::
name|standardIconImplementation
parameter_list|(
name|StandardPixmap
name|standardIcon
parameter_list|,
specifier|const
name|QStyleOption
modifier|*
name|opt
parameter_list|,
specifier|const
name|QWidget
modifier|*
name|widget
parameter_list|)
specifier|const
block|{
return|return
name|QMotifStyle
operator|::
name|standardIconImplementation
argument_list|(
name|standardIcon
argument_list|,
name|opt
argument_list|,
name|widget
argument_list|)
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
end_unit
