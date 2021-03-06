begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"view.h"
end_include
begin_include
include|#
directive|include
file|<QtGui>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|Q_DEAD_CODE_FROM_QT4_WIN
end_ifdef
begin_define
DECL|macro|CALLGRIND_START_INSTRUMENTATION
define|#
directive|define
name|CALLGRIND_START_INSTRUMENTATION
value|{}
end_define
begin_define
DECL|macro|CALLGRIND_STOP_INSTRUMENTATION
define|#
directive|define
name|CALLGRIND_STOP_INSTRUMENTATION
value|{}
end_define
begin_else
else|#
directive|else
end_else
begin_include
include|#
directive|include
file|"valgrind/callgrind.h"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_OPENGL
end_ifndef
begin_include
include|#
directive|include
file|<QtOpenGL>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|<qmath.h>
end_include
begin_class
DECL|class|CountView
class|class
name|CountView
super|:
specifier|public
name|QGraphicsView
block|{
protected|protected:
DECL|function|paintEvent
name|void
name|paintEvent
parameter_list|(
name|QPaintEvent
modifier|*
name|event
parameter_list|)
block|{
specifier|static
name|int
name|n
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|n
condition|)
name|CALLGRIND_START_INSTRUMENTATION
name|QGraphicsView
operator|::
name|paintEvent
argument_list|(
name|event
argument_list|)
decl_stmt|;
if|if
condition|(
name|n
condition|)
name|CALLGRIND_STOP_INSTRUMENTATION
if|if
condition|(
operator|++
name|n
operator|==
literal|500
condition|)
name|qApp
operator|->
name|quit
argument_list|()
expr_stmt|;
block|}
block|}
class|;
end_class
begin_constructor
DECL|function|View
name|View
operator|::
name|View
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|,
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QFrame
argument_list|(
name|parent
argument_list|)
block|{
name|setFrameStyle
argument_list|(
name|Sunken
operator||
name|StyledPanel
argument_list|)
expr_stmt|;
name|graphicsView
operator|=
operator|new
name|CountView
expr_stmt|;
name|graphicsView
operator|->
name|setRenderHint
argument_list|(
name|QPainter
operator|::
name|Antialiasing
argument_list|,
literal|false
argument_list|)
expr_stmt|;
name|graphicsView
operator|->
name|setDragMode
argument_list|(
name|QGraphicsView
operator|::
name|RubberBandDrag
argument_list|)
expr_stmt|;
name|graphicsView
operator|->
name|setViewportUpdateMode
argument_list|(
name|QGraphicsView
operator|::
name|SmartViewportUpdate
argument_list|)
expr_stmt|;
name|int
name|size
init|=
name|style
argument_list|()
operator|->
name|pixelMetric
argument_list|(
name|QStyle
operator|::
name|PM_ToolBarIconSize
argument_list|)
decl_stmt|;
name|QSize
name|iconSize
argument_list|(
name|size
argument_list|,
name|size
argument_list|)
decl_stmt|;
name|QToolButton
modifier|*
name|zoomInIcon
init|=
operator|new
name|QToolButton
decl_stmt|;
name|zoomInIcon
operator|->
name|setAutoRepeat
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|zoomInIcon
operator|->
name|setAutoRepeatInterval
argument_list|(
literal|33
argument_list|)
expr_stmt|;
name|zoomInIcon
operator|->
name|setAutoRepeatDelay
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|zoomInIcon
operator|->
name|setIcon
argument_list|(
name|QPixmap
argument_list|(
literal|":/zoomin.png"
argument_list|)
argument_list|)
expr_stmt|;
name|zoomInIcon
operator|->
name|setIconSize
argument_list|(
name|iconSize
argument_list|)
expr_stmt|;
name|QToolButton
modifier|*
name|zoomOutIcon
init|=
operator|new
name|QToolButton
decl_stmt|;
name|zoomOutIcon
operator|->
name|setAutoRepeat
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|zoomOutIcon
operator|->
name|setAutoRepeatInterval
argument_list|(
literal|33
argument_list|)
expr_stmt|;
name|zoomOutIcon
operator|->
name|setAutoRepeatDelay
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|zoomOutIcon
operator|->
name|setIcon
argument_list|(
name|QPixmap
argument_list|(
literal|":/zoomout.png"
argument_list|)
argument_list|)
expr_stmt|;
name|zoomOutIcon
operator|->
name|setIconSize
argument_list|(
name|iconSize
argument_list|)
expr_stmt|;
name|zoomSlider
operator|=
operator|new
name|QSlider
expr_stmt|;
name|zoomSlider
operator|->
name|setMinimum
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|zoomSlider
operator|->
name|setMaximum
argument_list|(
literal|500
argument_list|)
expr_stmt|;
name|zoomSlider
operator|->
name|setValue
argument_list|(
literal|250
argument_list|)
expr_stmt|;
name|zoomSlider
operator|->
name|setTickPosition
argument_list|(
name|QSlider
operator|::
name|TicksRight
argument_list|)
expr_stmt|;
comment|// Zoom slider layout
name|QVBoxLayout
modifier|*
name|zoomSliderLayout
init|=
operator|new
name|QVBoxLayout
decl_stmt|;
name|zoomSliderLayout
operator|->
name|addWidget
argument_list|(
name|zoomInIcon
argument_list|)
expr_stmt|;
name|zoomSliderLayout
operator|->
name|addWidget
argument_list|(
name|zoomSlider
argument_list|)
expr_stmt|;
name|zoomSliderLayout
operator|->
name|addWidget
argument_list|(
name|zoomOutIcon
argument_list|)
expr_stmt|;
name|QToolButton
modifier|*
name|rotateLeftIcon
init|=
operator|new
name|QToolButton
decl_stmt|;
name|rotateLeftIcon
operator|->
name|setIcon
argument_list|(
name|QPixmap
argument_list|(
literal|":/rotateleft.png"
argument_list|)
argument_list|)
expr_stmt|;
name|rotateLeftIcon
operator|->
name|setIconSize
argument_list|(
name|iconSize
argument_list|)
expr_stmt|;
name|QToolButton
modifier|*
name|rotateRightIcon
init|=
operator|new
name|QToolButton
decl_stmt|;
name|rotateRightIcon
operator|->
name|setIcon
argument_list|(
name|QPixmap
argument_list|(
literal|":/rotateright.png"
argument_list|)
argument_list|)
expr_stmt|;
name|rotateRightIcon
operator|->
name|setIconSize
argument_list|(
name|iconSize
argument_list|)
expr_stmt|;
name|rotateSlider
operator|=
operator|new
name|QSlider
expr_stmt|;
name|rotateSlider
operator|->
name|setOrientation
argument_list|(
name|Qt
operator|::
name|Horizontal
argument_list|)
expr_stmt|;
name|rotateSlider
operator|->
name|setMinimum
argument_list|(
operator|-
literal|360
argument_list|)
expr_stmt|;
name|rotateSlider
operator|->
name|setMaximum
argument_list|(
literal|360
argument_list|)
expr_stmt|;
name|rotateSlider
operator|->
name|setValue
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|rotateSlider
operator|->
name|setTickPosition
argument_list|(
name|QSlider
operator|::
name|TicksBelow
argument_list|)
expr_stmt|;
comment|// Rotate slider layout
name|QHBoxLayout
modifier|*
name|rotateSliderLayout
init|=
operator|new
name|QHBoxLayout
decl_stmt|;
name|rotateSliderLayout
operator|->
name|addWidget
argument_list|(
name|rotateLeftIcon
argument_list|)
expr_stmt|;
name|rotateSliderLayout
operator|->
name|addWidget
argument_list|(
name|rotateSlider
argument_list|)
expr_stmt|;
name|rotateSliderLayout
operator|->
name|addWidget
argument_list|(
name|rotateRightIcon
argument_list|)
expr_stmt|;
name|resetButton
operator|=
operator|new
name|QToolButton
expr_stmt|;
name|resetButton
operator|->
name|setText
argument_list|(
name|tr
argument_list|(
literal|"0"
argument_list|)
argument_list|)
expr_stmt|;
name|resetButton
operator|->
name|setEnabled
argument_list|(
literal|false
argument_list|)
expr_stmt|;
comment|// Label layout
name|QHBoxLayout
modifier|*
name|labelLayout
init|=
operator|new
name|QHBoxLayout
decl_stmt|;
name|label
operator|=
operator|new
name|QLabel
argument_list|(
name|name
argument_list|)
expr_stmt|;
name|antialiasButton
operator|=
operator|new
name|QToolButton
expr_stmt|;
name|antialiasButton
operator|->
name|setText
argument_list|(
name|tr
argument_list|(
literal|"Antialiasing"
argument_list|)
argument_list|)
expr_stmt|;
name|antialiasButton
operator|->
name|setCheckable
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|antialiasButton
operator|->
name|setChecked
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|openGlButton
operator|=
operator|new
name|QToolButton
expr_stmt|;
name|openGlButton
operator|->
name|setText
argument_list|(
name|tr
argument_list|(
literal|"OpenGL"
argument_list|)
argument_list|)
expr_stmt|;
name|openGlButton
operator|->
name|setCheckable
argument_list|(
literal|true
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_OPENGL
name|openGlButton
operator|->
name|setEnabled
argument_list|(
name|QGLFormat
operator|::
name|hasOpenGL
argument_list|()
argument_list|)
expr_stmt|;
else|#
directive|else
name|openGlButton
operator|->
name|setEnabled
argument_list|(
literal|false
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|printButton
operator|=
operator|new
name|QToolButton
expr_stmt|;
name|printButton
operator|->
name|setIcon
argument_list|(
name|QIcon
argument_list|(
name|QPixmap
argument_list|(
literal|":/fileprint.png"
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|labelLayout
operator|->
name|addWidget
argument_list|(
name|label
argument_list|)
expr_stmt|;
name|labelLayout
operator|->
name|addStretch
argument_list|()
expr_stmt|;
name|labelLayout
operator|->
name|addWidget
argument_list|(
name|antialiasButton
argument_list|)
expr_stmt|;
name|labelLayout
operator|->
name|addWidget
argument_list|(
name|openGlButton
argument_list|)
expr_stmt|;
name|labelLayout
operator|->
name|addWidget
argument_list|(
name|printButton
argument_list|)
expr_stmt|;
name|QGridLayout
modifier|*
name|topLayout
init|=
operator|new
name|QGridLayout
decl_stmt|;
name|topLayout
operator|->
name|addLayout
argument_list|(
name|labelLayout
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|topLayout
operator|->
name|addWidget
argument_list|(
name|graphicsView
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|topLayout
operator|->
name|addLayout
argument_list|(
name|zoomSliderLayout
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|topLayout
operator|->
name|addLayout
argument_list|(
name|rotateSliderLayout
argument_list|,
literal|2
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|topLayout
operator|->
name|addWidget
argument_list|(
name|resetButton
argument_list|,
literal|2
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|setLayout
argument_list|(
name|topLayout
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|resetButton
argument_list|,
name|SIGNAL
argument_list|(
name|clicked
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|resetView
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|zoomSlider
argument_list|,
name|SIGNAL
argument_list|(
name|valueChanged
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|setupMatrix
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|rotateSlider
argument_list|,
name|SIGNAL
argument_list|(
name|valueChanged
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|setupMatrix
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|graphicsView
operator|->
name|verticalScrollBar
argument_list|()
argument_list|,
name|SIGNAL
argument_list|(
name|valueChanged
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|setResetButtonEnabled
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|graphicsView
operator|->
name|horizontalScrollBar
argument_list|()
argument_list|,
name|SIGNAL
argument_list|(
name|valueChanged
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|setResetButtonEnabled
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|antialiasButton
argument_list|,
name|SIGNAL
argument_list|(
name|toggled
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|toggleAntialiasing
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|openGlButton
argument_list|,
name|SIGNAL
argument_list|(
name|toggled
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|toggleOpenGL
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|rotateLeftIcon
argument_list|,
name|SIGNAL
argument_list|(
name|clicked
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|rotateLeft
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|rotateRightIcon
argument_list|,
name|SIGNAL
argument_list|(
name|clicked
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|rotateRight
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|zoomInIcon
argument_list|,
name|SIGNAL
argument_list|(
name|clicked
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|zoomIn
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|zoomOutIcon
argument_list|,
name|SIGNAL
argument_list|(
name|clicked
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|zoomOut
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|printButton
argument_list|,
name|SIGNAL
argument_list|(
name|clicked
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|print
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|setupMatrix
argument_list|()
expr_stmt|;
name|startTimer
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|view
name|QGraphicsView
modifier|*
name|View
operator|::
name|view
parameter_list|()
specifier|const
block|{
return|return
name|graphicsView
return|;
block|}
end_function
begin_function
DECL|function|resetView
name|void
name|View
operator|::
name|resetView
parameter_list|()
block|{
name|zoomSlider
operator|->
name|setValue
argument_list|(
literal|250
argument_list|)
expr_stmt|;
name|rotateSlider
operator|->
name|setValue
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|setupMatrix
argument_list|()
expr_stmt|;
name|graphicsView
operator|->
name|ensureVisible
argument_list|(
name|QRectF
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|resetButton
operator|->
name|setEnabled
argument_list|(
literal|false
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setResetButtonEnabled
name|void
name|View
operator|::
name|setResetButtonEnabled
parameter_list|()
block|{
name|resetButton
operator|->
name|setEnabled
argument_list|(
literal|true
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setupMatrix
name|void
name|View
operator|::
name|setupMatrix
parameter_list|()
block|{
name|qreal
name|scale
init|=
name|qPow
argument_list|(
name|qreal
argument_list|(
literal|2
argument_list|)
argument_list|,
operator|(
name|zoomSlider
operator|->
name|value
argument_list|()
operator|-
literal|250
operator|)
operator|/
name|qreal
argument_list|(
literal|50
argument_list|)
argument_list|)
decl_stmt|;
name|QMatrix
name|matrix
decl_stmt|;
name|matrix
operator|.
name|scale
argument_list|(
name|scale
argument_list|,
name|scale
argument_list|)
expr_stmt|;
name|matrix
operator|.
name|rotate
argument_list|(
name|rotateSlider
operator|->
name|value
argument_list|()
argument_list|)
expr_stmt|;
name|graphicsView
operator|->
name|setMatrix
argument_list|(
name|matrix
argument_list|)
expr_stmt|;
name|setResetButtonEnabled
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|toggleOpenGL
name|void
name|View
operator|::
name|toggleOpenGL
parameter_list|()
block|{
ifndef|#
directive|ifndef
name|QT_NO_OPENGL
name|graphicsView
operator|->
name|setViewport
argument_list|(
name|openGlButton
operator|->
name|isChecked
argument_list|()
condition|?
operator|new
name|QGLWidget
argument_list|(
name|QGLFormat
argument_list|(
name|QGL
operator|::
name|SampleBuffers
argument_list|)
argument_list|)
else|:
operator|new
name|QWidget
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|toggleAntialiasing
name|void
name|View
operator|::
name|toggleAntialiasing
parameter_list|()
block|{
name|graphicsView
operator|->
name|setRenderHint
argument_list|(
name|QPainter
operator|::
name|Antialiasing
argument_list|,
name|antialiasButton
operator|->
name|isChecked
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|print
name|void
name|View
operator|::
name|print
parameter_list|()
block|{
ifndef|#
directive|ifndef
name|QT_NO_PRINTER
name|QPrinter
name|printer
decl_stmt|;
name|QPrintDialog
name|dialog
argument_list|(
operator|&
name|printer
argument_list|,
name|this
argument_list|)
decl_stmt|;
if|if
condition|(
name|dialog
operator|.
name|exec
argument_list|()
operator|==
name|QDialog
operator|::
name|Accepted
condition|)
block|{
name|QPainter
name|painter
argument_list|(
operator|&
name|printer
argument_list|)
decl_stmt|;
name|graphicsView
operator|->
name|render
argument_list|(
operator|&
name|painter
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|zoomIn
name|void
name|View
operator|::
name|zoomIn
parameter_list|()
block|{
name|zoomSlider
operator|->
name|setValue
argument_list|(
name|zoomSlider
operator|->
name|value
argument_list|()
operator|+
literal|1
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|zoomOut
name|void
name|View
operator|::
name|zoomOut
parameter_list|()
block|{
name|zoomSlider
operator|->
name|setValue
argument_list|(
name|zoomSlider
operator|->
name|value
argument_list|()
operator|-
literal|1
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|rotateLeft
name|void
name|View
operator|::
name|rotateLeft
parameter_list|()
block|{
name|rotateSlider
operator|->
name|setValue
argument_list|(
name|rotateSlider
operator|->
name|value
argument_list|()
operator|-
literal|10
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|rotateRight
name|void
name|View
operator|::
name|rotateRight
parameter_list|()
block|{
name|rotateSlider
operator|->
name|setValue
argument_list|(
name|rotateSlider
operator|->
name|value
argument_list|()
operator|+
literal|10
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|timerEvent
name|void
name|View
operator|::
name|timerEvent
parameter_list|(
name|QTimerEvent
modifier|*
parameter_list|)
block|{
name|graphicsView
operator|->
name|horizontalScrollBar
argument_list|()
operator|->
name|setValue
argument_list|(
name|graphicsView
operator|->
name|horizontalScrollBar
argument_list|()
operator|->
name|value
argument_list|()
operator|+
literal|1
argument_list|)
expr_stmt|;
block|}
end_function
end_unit
