begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qfocusframe.h"
end_include
begin_include
include|#
directive|include
file|"qstyle.h"
end_include
begin_include
include|#
directive|include
file|"qbitmap.h"
end_include
begin_include
include|#
directive|include
file|"qstylepainter.h"
end_include
begin_include
include|#
directive|include
file|"qstyleoption.h"
end_include
begin_include
include|#
directive|include
file|"qdebug.h"
end_include
begin_include
include|#
directive|include
file|<private/qwidget_p.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_class
DECL|class|QFocusFramePrivate
class|class
name|QFocusFramePrivate
super|:
specifier|public
name|QWidgetPrivate
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QFocusFrame
argument_list|)
DECL|member|widget
name|QWidget
modifier|*
name|widget
decl_stmt|;
DECL|member|frameParent
name|QWidget
modifier|*
name|frameParent
decl_stmt|;
DECL|member|showFrameAboveWidget
name|bool
name|showFrameAboveWidget
decl_stmt|;
public|public:
DECL|function|QFocusFramePrivate
name|QFocusFramePrivate
parameter_list|()
block|{
name|widget
operator|=
literal|0
expr_stmt|;
name|frameParent
operator|=
literal|0
expr_stmt|;
name|sendChildEvents
operator|=
literal|false
expr_stmt|;
name|showFrameAboveWidget
operator|=
literal|false
expr_stmt|;
block|}
name|void
name|updateSize
parameter_list|()
function_decl|;
name|void
name|update
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|update
name|void
name|QFocusFramePrivate
operator|::
name|update
parameter_list|()
block|{
name|Q_Q
argument_list|(
name|QFocusFrame
argument_list|)
expr_stmt|;
name|q
operator|->
name|setParent
argument_list|(
name|frameParent
argument_list|)
expr_stmt|;
name|updateSize
argument_list|()
expr_stmt|;
if|if
condition|(
name|q
operator|->
name|parentWidget
argument_list|()
operator|->
name|rect
argument_list|()
operator|.
name|intersects
argument_list|(
name|q
operator|->
name|geometry
argument_list|()
argument_list|)
condition|)
block|{
if|if
condition|(
name|showFrameAboveWidget
condition|)
name|q
operator|->
name|raise
argument_list|()
expr_stmt|;
else|else
name|q
operator|->
name|stackUnder
argument_list|(
name|widget
argument_list|)
expr_stmt|;
name|q
operator|->
name|show
argument_list|()
expr_stmt|;
block|}
else|else
block|{
name|q
operator|->
name|hide
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|updateSize
name|void
name|QFocusFramePrivate
operator|::
name|updateSize
parameter_list|()
block|{
name|Q_Q
argument_list|(
name|QFocusFrame
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|widget
condition|)
return|return;
name|int
name|vmargin
init|=
name|q
operator|->
name|style
argument_list|()
operator|->
name|pixelMetric
argument_list|(
name|QStyle
operator|::
name|PM_FocusFrameVMargin
argument_list|)
decl_stmt|,
name|hmargin
init|=
name|q
operator|->
name|style
argument_list|()
operator|->
name|pixelMetric
argument_list|(
name|QStyle
operator|::
name|PM_FocusFrameHMargin
argument_list|)
decl_stmt|;
name|QPoint
name|pos
argument_list|(
name|widget
operator|->
name|x
argument_list|()
argument_list|,
name|widget
operator|->
name|y
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|q
operator|->
name|parentWidget
argument_list|()
operator|!=
name|widget
operator|->
name|parentWidget
argument_list|()
condition|)
name|pos
operator|=
name|widget
operator|->
name|parentWidget
argument_list|()
operator|->
name|mapTo
argument_list|(
name|q
operator|->
name|parentWidget
argument_list|()
argument_list|,
name|pos
argument_list|)
expr_stmt|;
name|QRect
name|geom
argument_list|(
name|pos
operator|.
name|x
argument_list|()
operator|-
name|hmargin
argument_list|,
name|pos
operator|.
name|y
argument_list|()
operator|-
name|vmargin
argument_list|,
name|widget
operator|->
name|width
argument_list|()
operator|+
operator|(
name|hmargin
operator|*
literal|2
operator|)
argument_list|,
name|widget
operator|->
name|height
argument_list|()
operator|+
operator|(
name|vmargin
operator|*
literal|2
operator|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|q
operator|->
name|geometry
argument_list|()
operator|==
name|geom
condition|)
return|return;
name|q
operator|->
name|setGeometry
argument_list|(
name|geom
argument_list|)
expr_stmt|;
name|QStyleHintReturnMask
name|mask
decl_stmt|;
name|QStyleOption
name|opt
decl_stmt|;
name|q
operator|->
name|initStyleOption
argument_list|(
operator|&
name|opt
argument_list|)
expr_stmt|;
if|if
condition|(
name|q
operator|->
name|style
argument_list|()
operator|->
name|styleHint
argument_list|(
name|QStyle
operator|::
name|SH_FocusFrame_Mask
argument_list|,
operator|&
name|opt
argument_list|,
name|q
argument_list|,
operator|&
name|mask
argument_list|)
condition|)
name|q
operator|->
name|setMask
argument_list|(
name|mask
operator|.
name|region
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Initialize \a option with the values from this QFocusFrame. This method is useful     for subclasses when they need a QStyleOption, but don't want to fill     in all the information themselves.      \sa QStyleOption::initFrom() */
end_comment
begin_function
DECL|function|initStyleOption
name|void
name|QFocusFrame
operator|::
name|initStyleOption
parameter_list|(
name|QStyleOption
modifier|*
name|option
parameter_list|)
specifier|const
block|{
if|if
condition|(
operator|!
name|option
condition|)
return|return;
name|option
operator|->
name|initFrom
argument_list|(
name|this
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \class QFocusFrame     \brief The QFocusFrame widget provides a focus frame which can be     outside of a widget's normal paintable area.      \ingroup basicwidgets     \inmodule QtWidgets      Normally an application will not need to create its own     QFocusFrame as QStyle will handle this detail for     you. A style writer can optionally use a QFocusFrame to have a     focus area outside of the widget's paintable geometry. In this way     space need not be reserved for the widget to have focus but only     set on a QWidget with QFocusFrame::setWidget. It is, however,     legal to create your own QFocusFrame on a custom widget and set     its geometry manually via QWidget::setGeometry however you will     not get auto-placement when the focused widget changes size or     placement. */
end_comment
begin_comment
comment|/*!     Constructs a QFocusFrame.      The focus frame will not monitor \a parent for updates but rather     can be placed manually or by using QFocusFrame::setWidget. A     QFocusFrame sets Qt::WA_NoChildEventsForParent attribute; as a     result the parent will not receive a QEvent::ChildAdded event,     this will make it possible to manually set the geometry of the     QFocusFrame inside of a QSplitter or other child event monitoring     widget.      \sa QFocusFrame::setWidget() */
end_comment
begin_constructor
DECL|function|QFocusFrame
name|QFocusFrame
operator|::
name|QFocusFrame
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QWidget
argument_list|(
operator|*
operator|new
name|QFocusFramePrivate
argument_list|,
name|parent
argument_list|,
literal|0
argument_list|)
block|{
name|setAttribute
argument_list|(
name|Qt
operator|::
name|WA_TransparentForMouseEvents
argument_list|)
expr_stmt|;
name|setFocusPolicy
argument_list|(
name|Qt
operator|::
name|NoFocus
argument_list|)
expr_stmt|;
name|setAttribute
argument_list|(
name|Qt
operator|::
name|WA_NoChildEventsForParent
argument_list|,
literal|true
argument_list|)
expr_stmt|;
name|setAttribute
argument_list|(
name|Qt
operator|::
name|WA_AcceptDrops
argument_list|,
name|style
argument_list|()
operator|->
name|styleHint
argument_list|(
name|QStyle
operator|::
name|SH_FocusFrame_AboveWidget
argument_list|,
literal|0
argument_list|,
name|this
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!     Destructor. */
end_comment
begin_destructor
DECL|function|~QFocusFrame
name|QFocusFrame
operator|::
name|~
name|QFocusFrame
parameter_list|()
block|{ }
end_destructor
begin_comment
comment|/*!   QFocusFrame will track changes to \a widget and resize itself automatically.   If the monitored widget's parent changes, QFocusFrame will follow the widget   and place itself around the widget automatically. If the monitored widget is deleted,   QFocusFrame will set it to zero.    \sa QFocusFrame::widget() */
end_comment
begin_function
name|void
DECL|function|setWidget
name|QFocusFrame
operator|::
name|setWidget
parameter_list|(
name|QWidget
modifier|*
name|widget
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QFocusFrame
argument_list|)
expr_stmt|;
if|if
condition|(
name|style
argument_list|()
operator|->
name|styleHint
argument_list|(
name|QStyle
operator|::
name|SH_FocusFrame_AboveWidget
argument_list|,
literal|0
argument_list|,
name|this
argument_list|)
condition|)
name|d
operator|->
name|showFrameAboveWidget
operator|=
literal|true
expr_stmt|;
else|else
name|d
operator|->
name|showFrameAboveWidget
operator|=
literal|false
expr_stmt|;
if|if
condition|(
name|widget
operator|==
name|d
operator|->
name|widget
condition|)
return|return;
if|if
condition|(
name|d
operator|->
name|widget
condition|)
block|{
comment|// Remove event filters from the widget hierarchy.
name|QWidget
modifier|*
name|p
init|=
name|d
operator|->
name|widget
decl_stmt|;
do|do
block|{
name|p
operator|->
name|removeEventFilter
argument_list|(
name|this
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|d
operator|->
name|showFrameAboveWidget
operator|||
name|p
operator|==
name|d
operator|->
name|frameParent
condition|)
break|break;
name|p
operator|=
name|p
operator|->
name|parentWidget
argument_list|()
expr_stmt|;
block|}
do|while
condition|(
name|p
condition|)
do|;
block|}
if|if
condition|(
name|widget
operator|&&
operator|!
name|widget
operator|->
name|isWindow
argument_list|()
operator|&&
name|widget
operator|->
name|parentWidget
argument_list|()
operator|->
name|windowType
argument_list|()
operator|!=
name|Qt
operator|::
name|SubWindow
condition|)
block|{
name|d
operator|->
name|widget
operator|=
name|widget
expr_stmt|;
name|d
operator|->
name|widget
operator|->
name|installEventFilter
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|QWidget
modifier|*
name|p
init|=
name|widget
operator|->
name|parentWidget
argument_list|()
decl_stmt|;
name|QWidget
modifier|*
name|prev
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|d
operator|->
name|showFrameAboveWidget
condition|)
block|{
comment|// Find the right parent for the focus frame.
while|while
condition|(
name|p
condition|)
block|{
comment|// Traverse the hirerarchy of the 'widget' for setting event filter.
comment|// During this if come across toolbar or a top level, use that
comment|// as the parent for the focus frame. If we find a scroll area
comment|// use its viewport as the parent.
name|bool
name|isScrollArea
init|=
literal|false
decl_stmt|;
if|if
condition|(
name|p
operator|->
name|isWindow
argument_list|()
operator|||
name|p
operator|->
name|inherits
argument_list|(
literal|"QToolBar"
argument_list|)
operator|||
operator|(
name|isScrollArea
operator|=
name|p
operator|->
name|inherits
argument_list|(
literal|"QAbstractScrollArea"
argument_list|)
operator|)
condition|)
block|{
name|d
operator|->
name|frameParent
operator|=
name|p
expr_stmt|;
comment|// The previous one in the hierarchy will be the viewport.
if|if
condition|(
name|prev
operator|&&
name|isScrollArea
condition|)
name|d
operator|->
name|frameParent
operator|=
name|prev
expr_stmt|;
break|break;
block|}
else|else
block|{
name|p
operator|->
name|installEventFilter
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|prev
operator|=
name|p
expr_stmt|;
name|p
operator|=
name|p
operator|->
name|parentWidget
argument_list|()
expr_stmt|;
block|}
block|}
block|}
else|else
block|{
name|d
operator|->
name|frameParent
operator|=
name|p
expr_stmt|;
block|}
name|d
operator|->
name|update
argument_list|()
expr_stmt|;
block|}
else|else
block|{
name|d
operator|->
name|widget
operator|=
literal|0
expr_stmt|;
name|hide
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|/*!   Returns the currently monitored widget for automatically resize and   update.     \sa QFocusFrame::setWidget() */
end_comment
begin_function
name|QWidget
modifier|*
DECL|function|widget
name|QFocusFrame
operator|::
name|widget
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QFocusFrame
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|widget
return|;
block|}
end_function
begin_comment
comment|/*! \reimp */
end_comment
begin_function
name|void
DECL|function|paintEvent
name|QFocusFrame
operator|::
name|paintEvent
parameter_list|(
name|QPaintEvent
modifier|*
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QFocusFrame
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|d
operator|->
name|widget
condition|)
return|return;
name|QStylePainter
name|p
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|QStyleOption
name|option
decl_stmt|;
name|initStyleOption
argument_list|(
operator|&
name|option
argument_list|)
expr_stmt|;
name|int
name|vmargin
init|=
name|style
argument_list|()
operator|->
name|pixelMetric
argument_list|(
name|QStyle
operator|::
name|PM_FocusFrameVMargin
argument_list|)
decl_stmt|;
name|int
name|hmargin
init|=
name|style
argument_list|()
operator|->
name|pixelMetric
argument_list|(
name|QStyle
operator|::
name|PM_FocusFrameHMargin
argument_list|)
decl_stmt|;
name|QWidgetPrivate
modifier|*
name|wd
init|=
name|qt_widget_private
argument_list|(
name|d
operator|->
name|widget
argument_list|)
decl_stmt|;
name|QRect
name|rect
init|=
name|wd
operator|->
name|clipRect
argument_list|()
operator|.
name|adjusted
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|hmargin
operator|*
literal|2
argument_list|,
name|vmargin
operator|*
literal|2
argument_list|)
decl_stmt|;
name|p
operator|.
name|setClipRect
argument_list|(
name|rect
argument_list|)
expr_stmt|;
name|p
operator|.
name|drawControl
argument_list|(
name|QStyle
operator|::
name|CE_FocusFrame
argument_list|,
name|option
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*! \reimp */
end_comment
begin_function
name|bool
DECL|function|eventFilter
name|QFocusFrame
operator|::
name|eventFilter
parameter_list|(
name|QObject
modifier|*
name|o
parameter_list|,
name|QEvent
modifier|*
name|e
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QFocusFrame
argument_list|)
expr_stmt|;
if|if
condition|(
name|o
operator|==
name|d
operator|->
name|widget
condition|)
block|{
switch|switch
condition|(
name|e
operator|->
name|type
argument_list|()
condition|)
block|{
case|case
name|QEvent
operator|::
name|Move
case|:
case|case
name|QEvent
operator|::
name|Resize
case|:
name|d
operator|->
name|updateSize
argument_list|()
expr_stmt|;
break|break;
case|case
name|QEvent
operator|::
name|Hide
case|:
case|case
name|QEvent
operator|::
name|StyleChange
case|:
name|hide
argument_list|()
expr_stmt|;
break|break;
case|case
name|QEvent
operator|::
name|ParentChange
case|:
if|if
condition|(
name|d
operator|->
name|showFrameAboveWidget
condition|)
block|{
name|QWidget
modifier|*
name|w
init|=
name|d
operator|->
name|widget
decl_stmt|;
name|setWidget
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|setWidget
argument_list|(
name|w
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|d
operator|->
name|update
argument_list|()
expr_stmt|;
block|}
break|break;
case|case
name|QEvent
operator|::
name|Show
case|:
name|d
operator|->
name|update
argument_list|()
expr_stmt|;
name|show
argument_list|()
expr_stmt|;
break|break;
case|case
name|QEvent
operator|::
name|PaletteChange
case|:
name|setPalette
argument_list|(
name|d
operator|->
name|widget
operator|->
name|palette
argument_list|()
argument_list|)
expr_stmt|;
break|break;
case|case
name|QEvent
operator|::
name|ZOrderChange
case|:
if|if
condition|(
name|style
argument_list|()
operator|->
name|styleHint
argument_list|(
name|QStyle
operator|::
name|SH_FocusFrame_AboveWidget
argument_list|,
literal|0
argument_list|,
name|this
argument_list|)
condition|)
name|raise
argument_list|()
expr_stmt|;
else|else
name|stackUnder
argument_list|(
name|d
operator|->
name|widget
argument_list|)
expr_stmt|;
break|break;
case|case
name|QEvent
operator|::
name|Destroy
case|:
name|setWidget
argument_list|(
literal|0
argument_list|)
expr_stmt|;
break|break;
default|default:
break|break;
block|}
block|}
elseif|else
if|if
condition|(
name|d
operator|->
name|showFrameAboveWidget
condition|)
block|{
comment|// Handle changes in the parent widgets we are monitoring.
switch|switch
condition|(
name|e
operator|->
name|type
argument_list|()
condition|)
block|{
case|case
name|QEvent
operator|::
name|Move
case|:
case|case
name|QEvent
operator|::
name|Resize
case|:
name|d
operator|->
name|updateSize
argument_list|()
expr_stmt|;
break|break;
case|case
name|QEvent
operator|::
name|ZOrderChange
case|:
name|raise
argument_list|()
expr_stmt|;
break|break;
default|default:
break|break;
block|}
block|}
return|return
literal|false
return|;
block|}
end_function
begin_comment
comment|/*! \reimp */
end_comment
begin_function
DECL|function|event
name|bool
name|QFocusFrame
operator|::
name|event
parameter_list|(
name|QEvent
modifier|*
name|e
parameter_list|)
block|{
return|return
name|QWidget
operator|::
name|event
argument_list|(
name|e
argument_list|)
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
