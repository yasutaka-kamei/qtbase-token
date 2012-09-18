begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qprogressbar.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_PROGRESSBAR
end_ifndef
begin_include
include|#
directive|include
file|<qevent.h>
end_include
begin_include
include|#
directive|include
file|<qpainter.h>
end_include
begin_include
include|#
directive|include
file|<qstylepainter.h>
end_include
begin_include
include|#
directive|include
file|<qstyleoption.h>
end_include
begin_include
include|#
directive|include
file|<private/qwidget_p.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_ACCESSIBILITY
end_ifndef
begin_include
include|#
directive|include
file|<qaccessible.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|<limits.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_class
DECL|class|QProgressBarPrivate
class|class
name|QProgressBarPrivate
super|:
specifier|public
name|QWidgetPrivate
block|{
name|Q_DECLARE_PUBLIC
parameter_list|(
name|QProgressBar
parameter_list|)
specifier|public
private|:
name|QProgressBarPrivate
parameter_list|()
constructor_decl|;
name|void
name|init
parameter_list|()
function_decl|;
specifier|inline
name|void
name|resetLayoutItemMargins
parameter_list|()
function_decl|;
DECL|member|minimum
name|int
name|minimum
decl_stmt|;
DECL|member|maximum
name|int
name|maximum
decl_stmt|;
DECL|member|value
name|int
name|value
decl_stmt|;
DECL|member|alignment
name|Qt
operator|::
name|Alignment
name|alignment
decl_stmt|;
name|uint
name|textVisible
range|:
literal|1
decl_stmt|;
DECL|member|lastPaintedValue
name|int
name|lastPaintedValue
decl_stmt|;
DECL|member|orientation
name|Qt
operator|::
name|Orientation
name|orientation
decl_stmt|;
DECL|member|invertedAppearance
name|bool
name|invertedAppearance
decl_stmt|;
DECL|member|textDirection
name|QProgressBar
operator|::
name|Direction
name|textDirection
decl_stmt|;
DECL|member|format
name|QString
name|format
decl_stmt|;
DECL|function|bound
specifier|inline
name|int
name|bound
parameter_list|(
name|int
name|val
parameter_list|)
specifier|const
block|{
return|return
name|qMax
argument_list|(
name|minimum
operator|-
literal|1
argument_list|,
name|qMin
argument_list|(
name|maximum
argument_list|,
name|val
argument_list|)
argument_list|)
return|;
block|}
name|bool
name|repaintRequired
parameter_list|()
specifier|const
function_decl|;
block|}
class|;
end_class
begin_constructor
DECL|function|QProgressBarPrivate
name|QProgressBarPrivate
operator|::
name|QProgressBarPrivate
parameter_list|()
member_init_list|:
name|minimum
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|maximum
argument_list|(
literal|100
argument_list|)
member_init_list|,
name|value
argument_list|(
operator|-
literal|1
argument_list|)
member_init_list|,
name|alignment
argument_list|(
name|Qt
operator|::
name|AlignLeft
argument_list|)
member_init_list|,
name|textVisible
argument_list|(
literal|true
argument_list|)
member_init_list|,
name|lastPaintedValue
argument_list|(
operator|-
literal|1
argument_list|)
member_init_list|,
name|orientation
argument_list|(
name|Qt
operator|::
name|Horizontal
argument_list|)
member_init_list|,
name|invertedAppearance
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|textDirection
argument_list|(
name|QProgressBar
operator|::
name|TopToBottom
argument_list|)
member_init_list|,
name|format
argument_list|(
name|QLatin1String
argument_list|(
literal|"%p%"
argument_list|)
argument_list|)
block|{ }
end_constructor
begin_function
DECL|function|init
name|void
name|QProgressBarPrivate
operator|::
name|init
parameter_list|()
block|{
name|Q_Q
argument_list|(
name|QProgressBar
argument_list|)
expr_stmt|;
name|QSizePolicy
name|sp
argument_list|(
name|QSizePolicy
operator|::
name|Expanding
argument_list|,
name|QSizePolicy
operator|::
name|Fixed
argument_list|)
decl_stmt|;
if|if
condition|(
name|orientation
operator|==
name|Qt
operator|::
name|Vertical
condition|)
name|sp
operator|.
name|transpose
argument_list|()
expr_stmt|;
name|q
operator|->
name|setSizePolicy
argument_list|(
name|sp
argument_list|)
expr_stmt|;
name|q
operator|->
name|setAttribute
argument_list|(
name|Qt
operator|::
name|WA_WState_OwnSizePolicy
argument_list|,
literal|false
argument_list|)
expr_stmt|;
name|resetLayoutItemMargins
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|resetLayoutItemMargins
name|void
name|QProgressBarPrivate
operator|::
name|resetLayoutItemMargins
parameter_list|()
block|{
name|Q_Q
argument_list|(
name|QProgressBar
argument_list|)
expr_stmt|;
name|QStyleOptionProgressBar
name|option
decl_stmt|;
name|q
operator|->
name|initStyleOption
argument_list|(
operator|&
name|option
argument_list|)
expr_stmt|;
name|setLayoutItemMargins
argument_list|(
name|QStyle
operator|::
name|SE_ProgressBarLayoutItem
argument_list|,
operator|&
name|option
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Initialize \a option with the values from this QProgressBar. This method is useful     for subclasses when they need a QStyleOptionProgressBar or QStyleOptionProgressBarV2,     but don't want to fill in all the information themselves. This function will check the version     of the QStyleOptionProgressBar and fill in the additional values for a     QStyleOptionProgressBarV2.      \sa QStyleOption::initFrom() */
end_comment
begin_function
DECL|function|initStyleOption
name|void
name|QProgressBar
operator|::
name|initStyleOption
parameter_list|(
name|QStyleOptionProgressBar
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
name|Q_D
argument_list|(
specifier|const
name|QProgressBar
argument_list|)
expr_stmt|;
name|option
operator|->
name|initFrom
argument_list|(
name|this
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|orientation
operator|==
name|Qt
operator|::
name|Horizontal
condition|)
name|option
operator|->
name|state
operator||=
name|QStyle
operator|::
name|State_Horizontal
expr_stmt|;
name|option
operator|->
name|minimum
operator|=
name|d
operator|->
name|minimum
expr_stmt|;
name|option
operator|->
name|maximum
operator|=
name|d
operator|->
name|maximum
expr_stmt|;
name|option
operator|->
name|progress
operator|=
name|d
operator|->
name|value
expr_stmt|;
name|option
operator|->
name|textAlignment
operator|=
name|d
operator|->
name|alignment
expr_stmt|;
name|option
operator|->
name|textVisible
operator|=
name|d
operator|->
name|textVisible
expr_stmt|;
name|option
operator|->
name|text
operator|=
name|text
argument_list|()
expr_stmt|;
if|if
condition|(
name|QStyleOptionProgressBarV2
modifier|*
name|optionV2
init|=
name|qstyleoption_cast
argument_list|<
name|QStyleOptionProgressBarV2
operator|*
argument_list|>
argument_list|(
name|option
argument_list|)
condition|)
block|{
name|optionV2
operator|->
name|orientation
operator|=
name|d
operator|->
name|orientation
expr_stmt|;
comment|// ### Qt 5: use State_Horizontal instead
name|optionV2
operator|->
name|invertedAppearance
operator|=
name|d
operator|->
name|invertedAppearance
expr_stmt|;
name|optionV2
operator|->
name|bottomToTop
operator|=
operator|(
name|d
operator|->
name|textDirection
operator|==
name|QProgressBar
operator|::
name|BottomToTop
operator|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|repaintRequired
name|bool
name|QProgressBarPrivate
operator|::
name|repaintRequired
parameter_list|()
specifier|const
block|{
name|Q_Q
argument_list|(
specifier|const
name|QProgressBar
argument_list|)
expr_stmt|;
if|if
condition|(
name|value
operator|==
name|lastPaintedValue
condition|)
return|return
literal|false
return|;
name|int
name|valueDifference
init|=
name|qAbs
argument_list|(
name|value
operator|-
name|lastPaintedValue
argument_list|)
decl_stmt|;
comment|// Check if the text needs to be repainted
if|if
condition|(
name|value
operator|==
name|minimum
operator|||
name|value
operator|==
name|maximum
condition|)
return|return
literal|true
return|;
if|if
condition|(
name|textVisible
condition|)
block|{
if|if
condition|(
operator|(
name|format
operator|.
name|contains
argument_list|(
name|QLatin1String
argument_list|(
literal|"%v"
argument_list|)
argument_list|)
operator|)
condition|)
return|return
literal|true
return|;
if|if
condition|(
operator|(
name|format
operator|.
name|contains
argument_list|(
name|QLatin1String
argument_list|(
literal|"%p"
argument_list|)
argument_list|)
operator|&&
name|valueDifference
operator|>=
name|qAbs
argument_list|(
operator|(
name|maximum
operator|-
name|minimum
operator|)
operator|/
literal|100
argument_list|)
operator|)
condition|)
return|return
literal|true
return|;
block|}
comment|// Check if the bar needs to be repainted
name|QStyleOptionProgressBarV2
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
name|int
name|cw
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
name|PM_ProgressBarChunkWidth
argument_list|,
operator|&
name|opt
argument_list|,
name|q
argument_list|)
decl_stmt|;
name|QRect
name|groove
init|=
name|q
operator|->
name|style
argument_list|()
operator|->
name|subElementRect
argument_list|(
name|QStyle
operator|::
name|SE_ProgressBarGroove
argument_list|,
operator|&
name|opt
argument_list|,
name|q
argument_list|)
decl_stmt|;
comment|// This expression is basically
comment|// (valueDifference / (maximum - minimum)> cw / groove.width())
comment|// transformed to avoid integer division.
name|int
name|grooveBlock
init|=
operator|(
name|q
operator|->
name|orientation
argument_list|()
operator|==
name|Qt
operator|::
name|Horizontal
operator|)
condition|?
name|groove
operator|.
name|width
argument_list|()
else|:
name|groove
operator|.
name|height
argument_list|()
decl_stmt|;
return|return
operator|(
name|valueDifference
operator|*
name|grooveBlock
operator|>
name|cw
operator|*
operator|(
name|maximum
operator|-
name|minimum
operator|)
operator|)
return|;
block|}
end_function
begin_comment
comment|/*!     \class QProgressBar     \brief The QProgressBar widget provides a horizontal or vertical progress bar.      \ingroup basicwidgets     \inmodule QtWidgets      A progress bar is used to give the user an indication of the     progress of an operation and to reassure them that the application     is still running.      The progress bar uses the concept of \e steps. You set it up by     specifying the minimum and maximum possible step values, and it     will display the percentage of steps that have been completed     when you later give it the current step value. The percentage is     calculated by dividing the progress (value() - minimum()) divided     by maximum() - minimum().      You can specify the minimum and maximum number of steps with     setMinimum() and setMaximum. The current number of steps is set     with setValue(). The progress bar can be rewound to the     beginning with reset().      If minimum and maximum both are set to 0, the bar shows a busy     indicator instead of a percentage of steps. This is useful, for     example, when using QNetworkAccessManager to download items when     they are unable to determine the size of the item being downloaded.      \table     \row \li \inlineimage macintosh-progressbar.png Screenshot of a Macintosh style progress bar          \li A progress bar shown in the Macintosh widget style.     \row \li \inlineimage windowsxp-progressbar.png Screenshot of a Windows XP style progress bar          \li A progress bar shown in the Windows XP widget style.     \row \li \inlineimage plastique-progressbar.png Screenshot of a Plastique style progress bar          \li A progress bar shown in the Plastique widget style.     \endtable      \sa QProgressDialog, {fowler}{GUI Design Handbook: Progress Indicator} */
end_comment
begin_comment
comment|/*!     \since 4.1     \enum QProgressBar::Direction     \brief Specifies the reading direction of the \l text for vertical progress bars.      \value TopToBottom The text is rotated 90 degrees clockwise.     \value BottomToTop The text is rotated 90 degrees counter-clockwise.      Note that whether or not the text is drawn is dependent on the style.     Currently CleanLooks and Plastique draw the text. Mac, Windows     and WindowsXP style do not.      \sa textDirection */
end_comment
begin_comment
comment|/*!     \fn void QProgressBar::valueChanged(int value)      This signal is emitted when the value shown in the progress bar changes.     \a value is the new value shown by the progress bar. */
end_comment
begin_comment
comment|/*!     Constructs a progress bar with the given \a parent.      By default, the minimum step value is set to 0, and the maximum to 100.      \sa setRange() */
end_comment
begin_constructor
DECL|function|QProgressBar
name|QProgressBar
operator|::
name|QProgressBar
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QWidget
argument_list|(
operator|*
operator|(
operator|new
name|QProgressBarPrivate
operator|)
argument_list|,
name|parent
argument_list|,
literal|0
argument_list|)
block|{
name|d_func
argument_list|()
operator|->
name|init
argument_list|()
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!     Reset the progress bar. The progress bar "rewinds" and shows no     progress. */
end_comment
begin_function
DECL|function|reset
name|void
name|QProgressBar
operator|::
name|reset
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QProgressBar
argument_list|)
expr_stmt|;
name|d
operator|->
name|value
operator|=
name|d
operator|->
name|minimum
operator|-
literal|1
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|minimum
operator|==
name|INT_MIN
condition|)
name|d
operator|->
name|value
operator|=
name|INT_MIN
expr_stmt|;
name|repaint
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \property QProgressBar::minimum     \brief the progress bar's minimum value      When setting this property, the \l maximum is adjusted if     necessary to ensure that the range remains valid. If the     current value falls outside the new range, the progress bar is reset     with reset(). */
end_comment
begin_function
DECL|function|setMinimum
name|void
name|QProgressBar
operator|::
name|setMinimum
parameter_list|(
name|int
name|minimum
parameter_list|)
block|{
name|setRange
argument_list|(
name|minimum
argument_list|,
name|qMax
argument_list|(
name|d_func
argument_list|()
operator|->
name|maximum
argument_list|,
name|minimum
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|minimum
name|int
name|QProgressBar
operator|::
name|minimum
parameter_list|()
specifier|const
block|{
return|return
name|d_func
argument_list|()
operator|->
name|minimum
return|;
block|}
end_function
begin_comment
comment|/*!     \property QProgressBar::maximum     \brief the progress bar's maximum value      When setting this property, the \l minimum is adjusted if     necessary to ensure that the range remains valid. If the     current value falls outside the new range, the progress bar is reset     with reset(). */
end_comment
begin_function
DECL|function|setMaximum
name|void
name|QProgressBar
operator|::
name|setMaximum
parameter_list|(
name|int
name|maximum
parameter_list|)
block|{
name|setRange
argument_list|(
name|qMin
argument_list|(
name|d_func
argument_list|()
operator|->
name|minimum
argument_list|,
name|maximum
argument_list|)
argument_list|,
name|maximum
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|maximum
name|int
name|QProgressBar
operator|::
name|maximum
parameter_list|()
specifier|const
block|{
return|return
name|d_func
argument_list|()
operator|->
name|maximum
return|;
block|}
end_function
begin_comment
comment|/*!     \property QProgressBar::value     \brief the progress bar's current value      Attempting to change the current value to one outside     the minimum-maximum range has no effect on the current value. */
end_comment
begin_function
DECL|function|setValue
name|void
name|QProgressBar
operator|::
name|setValue
parameter_list|(
name|int
name|value
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QProgressBar
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|value
operator|==
name|value
operator|||
operator|(
operator|(
name|value
operator|>
name|d
operator|->
name|maximum
operator|||
name|value
operator|<
name|d
operator|->
name|minimum
operator|)
operator|&&
operator|(
name|d
operator|->
name|maximum
operator|!=
literal|0
operator|||
name|d
operator|->
name|minimum
operator|!=
literal|0
operator|)
operator|)
condition|)
return|return;
name|d
operator|->
name|value
operator|=
name|value
expr_stmt|;
emit|emit
name|valueChanged
argument_list|(
name|value
argument_list|)
emit|;
ifndef|#
directive|ifndef
name|QT_NO_ACCESSIBILITY
if|if
condition|(
name|isVisible
argument_list|()
condition|)
block|{
name|QAccessibleValueChangeEvent
name|event
argument_list|(
name|this
argument_list|,
name|value
argument_list|)
decl_stmt|;
name|QAccessible
operator|::
name|updateAccessibility
argument_list|(
operator|&
name|event
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
if|if
condition|(
name|d
operator|->
name|repaintRequired
argument_list|()
condition|)
name|repaint
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|value
name|int
name|QProgressBar
operator|::
name|value
parameter_list|()
specifier|const
block|{
return|return
name|d_func
argument_list|()
operator|->
name|value
return|;
block|}
end_function
begin_comment
comment|/*!     Sets the progress bar's minimum and maximum values to \a minimum and     \a maximum respectively.      If \a maximum is smaller than \a minimum, \a minimum becomes the only     legal value.      If the current value falls outside the new range, the progress bar is reset     with reset().      \sa minimum, maximum */
end_comment
begin_function
DECL|function|setRange
name|void
name|QProgressBar
operator|::
name|setRange
parameter_list|(
name|int
name|minimum
parameter_list|,
name|int
name|maximum
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QProgressBar
argument_list|)
expr_stmt|;
if|if
condition|(
name|minimum
operator|!=
name|d
operator|->
name|minimum
operator|||
name|maximum
operator|!=
name|d
operator|->
name|maximum
condition|)
block|{
name|d
operator|->
name|minimum
operator|=
name|minimum
expr_stmt|;
name|d
operator|->
name|maximum
operator|=
name|qMax
argument_list|(
name|minimum
argument_list|,
name|maximum
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|value
argument_list|<
operator|(
name|d
operator|->
name|minimum
operator|-
literal|1
operator|)
operator|||
name|d
operator|->
name|value
argument_list|>
name|d
operator|->
name|maximum
condition|)
name|reset
argument_list|()
expr_stmt|;
else|else
name|update
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|/*!     \property QProgressBar::textVisible     \brief whether the current completed percentage should be displayed      This property may be ignored by the style (e.g., QMacStyle never draws the text).      \sa textDirection */
end_comment
begin_function
DECL|function|setTextVisible
name|void
name|QProgressBar
operator|::
name|setTextVisible
parameter_list|(
name|bool
name|visible
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QProgressBar
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|textVisible
operator|!=
name|visible
condition|)
block|{
name|d
operator|->
name|textVisible
operator|=
name|visible
expr_stmt|;
name|repaint
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|isTextVisible
name|bool
name|QProgressBar
operator|::
name|isTextVisible
parameter_list|()
specifier|const
block|{
return|return
name|d_func
argument_list|()
operator|->
name|textVisible
return|;
block|}
end_function
begin_comment
comment|/*!     \property QProgressBar::alignment     \brief the alignment of the progress bar */
end_comment
begin_function
DECL|function|setAlignment
name|void
name|QProgressBar
operator|::
name|setAlignment
parameter_list|(
name|Qt
operator|::
name|Alignment
name|alignment
parameter_list|)
block|{
if|if
condition|(
name|d_func
argument_list|()
operator|->
name|alignment
operator|!=
name|alignment
condition|)
block|{
name|d_func
argument_list|()
operator|->
name|alignment
operator|=
name|alignment
expr_stmt|;
name|repaint
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|alignment
name|Qt
operator|::
name|Alignment
name|QProgressBar
operator|::
name|alignment
parameter_list|()
specifier|const
block|{
return|return
name|d_func
argument_list|()
operator|->
name|alignment
return|;
block|}
end_function
begin_comment
comment|/*!     \reimp */
end_comment
begin_function
DECL|function|paintEvent
name|void
name|QProgressBar
operator|::
name|paintEvent
parameter_list|(
name|QPaintEvent
modifier|*
parameter_list|)
block|{
name|QStylePainter
name|paint
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|QStyleOptionProgressBarV2
name|opt
decl_stmt|;
name|initStyleOption
argument_list|(
operator|&
name|opt
argument_list|)
expr_stmt|;
name|paint
operator|.
name|drawControl
argument_list|(
name|QStyle
operator|::
name|CE_ProgressBar
argument_list|,
name|opt
argument_list|)
expr_stmt|;
name|d_func
argument_list|()
operator|->
name|lastPaintedValue
operator|=
name|d_func
argument_list|()
operator|->
name|value
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \reimp */
end_comment
begin_function
DECL|function|sizeHint
name|QSize
name|QProgressBar
operator|::
name|sizeHint
parameter_list|()
specifier|const
block|{
name|ensurePolished
argument_list|()
expr_stmt|;
name|QFontMetrics
name|fm
init|=
name|fontMetrics
argument_list|()
decl_stmt|;
name|QStyleOptionProgressBarV2
name|opt
decl_stmt|;
name|initStyleOption
argument_list|(
operator|&
name|opt
argument_list|)
expr_stmt|;
name|int
name|cw
init|=
name|style
argument_list|()
operator|->
name|pixelMetric
argument_list|(
name|QStyle
operator|::
name|PM_ProgressBarChunkWidth
argument_list|,
operator|&
name|opt
argument_list|,
name|this
argument_list|)
decl_stmt|;
name|QSize
name|size
init|=
name|QSize
argument_list|(
name|qMax
argument_list|(
literal|9
argument_list|,
name|cw
argument_list|)
operator|*
literal|7
operator|+
name|fm
operator|.
name|width
argument_list|(
name|QLatin1Char
argument_list|(
literal|'0'
argument_list|)
argument_list|)
operator|*
literal|4
argument_list|,
name|fm
operator|.
name|height
argument_list|()
operator|+
literal|8
argument_list|)
decl_stmt|;
if|if
condition|(
name|opt
operator|.
name|orientation
operator|==
name|Qt
operator|::
name|Vertical
condition|)
name|size
operator|.
name|transpose
argument_list|()
expr_stmt|;
return|return
name|style
argument_list|()
operator|->
name|sizeFromContents
argument_list|(
name|QStyle
operator|::
name|CT_ProgressBar
argument_list|,
operator|&
name|opt
argument_list|,
name|size
argument_list|,
name|this
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     \reimp */
end_comment
begin_function
DECL|function|minimumSizeHint
name|QSize
name|QProgressBar
operator|::
name|minimumSizeHint
parameter_list|()
specifier|const
block|{
name|QSize
name|size
decl_stmt|;
if|if
condition|(
name|orientation
argument_list|()
operator|==
name|Qt
operator|::
name|Horizontal
condition|)
name|size
operator|=
name|QSize
argument_list|(
name|sizeHint
argument_list|()
operator|.
name|width
argument_list|()
argument_list|,
name|fontMetrics
argument_list|()
operator|.
name|height
argument_list|()
operator|+
literal|2
argument_list|)
expr_stmt|;
else|else
name|size
operator|=
name|QSize
argument_list|(
name|fontMetrics
argument_list|()
operator|.
name|height
argument_list|()
operator|+
literal|2
argument_list|,
name|sizeHint
argument_list|()
operator|.
name|height
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|size
return|;
block|}
end_function
begin_comment
comment|/*!     \property QProgressBar::text     \brief the descriptive text shown with the progress bar      The text returned is the same as the text displayed in the center     (or in some styles, to the left) of the progress bar.      The progress shown in the text may be smaller than the minimum value,     indicating that the progress bar is in the "reset" state before any     progress is set.      In the default implementation, the text either contains a percentage     value that indicates the progress so far, or it is blank because the     progress bar is in the reset state. */
end_comment
begin_function
DECL|function|text
name|QString
name|QProgressBar
operator|::
name|text
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QProgressBar
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|d
operator|->
name|maximum
operator|==
literal|0
operator|&&
name|d
operator|->
name|minimum
operator|==
literal|0
operator|)
operator|||
name|d
operator|->
name|value
operator|<
name|d
operator|->
name|minimum
operator|||
operator|(
name|d
operator|->
name|value
operator|==
name|INT_MIN
operator|&&
name|d
operator|->
name|minimum
operator|==
name|INT_MIN
operator|)
condition|)
return|return
name|QString
argument_list|()
return|;
name|qint64
name|totalSteps
init|=
name|qint64
argument_list|(
name|d
operator|->
name|maximum
argument_list|)
operator|-
name|d
operator|->
name|minimum
decl_stmt|;
name|QString
name|result
init|=
name|d
operator|->
name|format
decl_stmt|;
name|result
operator|.
name|replace
argument_list|(
name|QLatin1String
argument_list|(
literal|"%m"
argument_list|)
argument_list|,
name|QString
operator|::
name|number
argument_list|(
name|totalSteps
argument_list|)
argument_list|)
expr_stmt|;
name|result
operator|.
name|replace
argument_list|(
name|QLatin1String
argument_list|(
literal|"%v"
argument_list|)
argument_list|,
name|QString
operator|::
name|number
argument_list|(
name|d
operator|->
name|value
argument_list|)
argument_list|)
expr_stmt|;
comment|// If max and min are equal and we get this far, it means that the
comment|// progress bar has one step and that we are on that step. Return
comment|// 100% here in order to avoid division by zero further down.
if|if
condition|(
name|totalSteps
operator|==
literal|0
condition|)
block|{
name|result
operator|.
name|replace
argument_list|(
name|QLatin1String
argument_list|(
literal|"%p"
argument_list|)
argument_list|,
name|QString
operator|::
name|number
argument_list|(
literal|100
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|result
return|;
block|}
name|int
name|progress
init|=
operator|(
name|qreal
argument_list|(
name|d
operator|->
name|value
argument_list|)
operator|-
name|d
operator|->
name|minimum
operator|)
operator|*
literal|100.0
operator|/
name|totalSteps
decl_stmt|;
name|result
operator|.
name|replace
argument_list|(
name|QLatin1String
argument_list|(
literal|"%p"
argument_list|)
argument_list|,
name|QString
operator|::
name|number
argument_list|(
name|progress
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|result
return|;
block|}
end_function
begin_comment
comment|/*!     \since 4.1     \property QProgressBar::orientation     \brief the orientation of the progress bar      The orientation must be \l Qt::Horizontal (the default) or \l     Qt::Vertical.      \sa invertedAppearance, textDirection */
end_comment
begin_function
DECL|function|setOrientation
name|void
name|QProgressBar
operator|::
name|setOrientation
parameter_list|(
name|Qt
operator|::
name|Orientation
name|orientation
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QProgressBar
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|orientation
operator|==
name|orientation
condition|)
return|return;
name|d
operator|->
name|orientation
operator|=
name|orientation
expr_stmt|;
if|if
condition|(
operator|!
name|testAttribute
argument_list|(
name|Qt
operator|::
name|WA_WState_OwnSizePolicy
argument_list|)
condition|)
block|{
name|QSizePolicy
name|sp
init|=
name|sizePolicy
argument_list|()
decl_stmt|;
name|sp
operator|.
name|transpose
argument_list|()
expr_stmt|;
name|setSizePolicy
argument_list|(
name|sp
argument_list|)
expr_stmt|;
name|setAttribute
argument_list|(
name|Qt
operator|::
name|WA_WState_OwnSizePolicy
argument_list|,
literal|false
argument_list|)
expr_stmt|;
block|}
name|d
operator|->
name|resetLayoutItemMargins
argument_list|()
expr_stmt|;
name|update
argument_list|()
expr_stmt|;
name|updateGeometry
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|orientation
name|Qt
operator|::
name|Orientation
name|QProgressBar
operator|::
name|orientation
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QProgressBar
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|orientation
return|;
block|}
end_function
begin_comment
comment|/*!     \since 4.1     \property QProgressBar::invertedAppearance     \brief whether or not a progress bar shows its progress inverted      If this property is false, the progress bar grows in the other     direction (e.g. from right to left). By default, the progress bar     is not inverted.      \sa orientation, layoutDirection */
end_comment
begin_function
DECL|function|setInvertedAppearance
name|void
name|QProgressBar
operator|::
name|setInvertedAppearance
parameter_list|(
name|bool
name|invert
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QProgressBar
argument_list|)
expr_stmt|;
name|d
operator|->
name|invertedAppearance
operator|=
name|invert
expr_stmt|;
name|update
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|invertedAppearance
name|bool
name|QProgressBar
operator|::
name|invertedAppearance
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QProgressBar
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|invertedAppearance
return|;
block|}
end_function
begin_comment
comment|/*!     \since 4.1     \property QProgressBar::textDirection     \brief the reading direction of the \l text for vertical progress bars      This property has no impact on horizontal progress bars.     By default, the reading direction is QProgressBar::TopToBottom.      \sa orientation, textVisible */
end_comment
begin_function
DECL|function|setTextDirection
name|void
name|QProgressBar
operator|::
name|setTextDirection
parameter_list|(
name|QProgressBar
operator|::
name|Direction
name|textDirection
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QProgressBar
argument_list|)
expr_stmt|;
name|d
operator|->
name|textDirection
operator|=
name|textDirection
expr_stmt|;
name|update
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|textDirection
name|QProgressBar
operator|::
name|Direction
name|QProgressBar
operator|::
name|textDirection
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QProgressBar
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|textDirection
return|;
block|}
end_function
begin_comment
comment|/*! \reimp */
end_comment
begin_function
DECL|function|event
name|bool
name|QProgressBar
operator|::
name|event
parameter_list|(
name|QEvent
modifier|*
name|e
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QProgressBar
argument_list|)
expr_stmt|;
if|if
condition|(
name|e
operator|->
name|type
argument_list|()
operator|==
name|QEvent
operator|::
name|StyleChange
ifdef|#
directive|ifdef
name|Q_WS_MAC
operator|||
name|e
operator|->
name|type
argument_list|()
operator|==
name|QEvent
operator|::
name|MacSizeChange
endif|#
directive|endif
condition|)
name|d
operator|->
name|resetLayoutItemMargins
argument_list|()
expr_stmt|;
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
begin_comment
comment|/*!     \since 4.2     \property QProgressBar::format     \brief the string used to generate the current text      %p - is replaced by the percentage completed.     %v - is replaced by the current value.     %m - is replaced by the total number of steps.      The default value is "%p%".      \sa text() */
end_comment
begin_function
DECL|function|setFormat
name|void
name|QProgressBar
operator|::
name|setFormat
parameter_list|(
specifier|const
name|QString
modifier|&
name|format
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QProgressBar
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|format
operator|==
name|format
condition|)
return|return;
name|d
operator|->
name|format
operator|=
name|format
expr_stmt|;
name|update
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|format
name|QString
name|QProgressBar
operator|::
name|format
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QProgressBar
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|format
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
begin_comment
comment|// QT_NO_PROGRESSBAR
end_comment
end_unit
