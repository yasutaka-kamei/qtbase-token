begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|WIDGETS_H
end_ifndef
begin_define
DECL|macro|WIDGETS_H
define|#
directive|define
name|WIDGETS_H
end_define
begin_include
include|#
directive|include
file|"paintcommands.h"
end_include
begin_include
include|#
directive|include
file|<QWidget>
end_include
begin_include
include|#
directive|include
file|<QSettings>
end_include
begin_include
include|#
directive|include
file|<QFileInfo>
end_include
begin_include
include|#
directive|include
file|<QPainter>
end_include
begin_include
include|#
directive|include
file|<QPaintEvent>
end_include
begin_include
include|#
directive|include
file|<QListWidgetItem>
end_include
begin_include
include|#
directive|include
file|<QTextEdit>
end_include
begin_include
include|#
directive|include
file|<QHBoxLayout>
end_include
begin_include
include|#
directive|include
file|<QSplitter>
end_include
begin_include
include|#
directive|include
file|<QPushButton>
end_include
begin_include
include|#
directive|include
file|<QFileDialog>
end_include
begin_include
include|#
directive|include
file|<QTextStream>
end_include
begin_include
include|#
directive|include
file|<QPaintEngine>
end_include
begin_include
include|#
directive|include
file|<QSignalMapper>
end_include
begin_include
include|#
directive|include
file|<QAction>
end_include
begin_include
include|#
directive|include
file|<qmath.h>
end_include
begin_decl_stmt
DECL|variable|CP_RADIUS
specifier|const
name|int
name|CP_RADIUS
init|=
literal|10
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|StupidWorkaround
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
operator|:
name|StupidWorkaround
argument_list|(
name|QWidget
operator|*
name|widget
argument_list|,
name|int
operator|*
name|value
argument_list|)
operator|:
name|QObject
argument_list|(
name|widget
argument_list|)
block|,
name|w
argument_list|(
name|widget
argument_list|)
block|,
name|mode
argument_list|(
argument|value
argument_list|)
block|{     }
name|public
name|slots
operator|:
name|void
name|setViewMode
argument_list|(
argument|int m
argument_list|)
block|{
operator|*
name|mode
operator|=
name|m
block|;
name|w
operator|->
name|update
argument_list|()
block|;     }
name|private
operator|:
name|QWidget
operator|*
name|w
block|;
name|int
operator|*
name|mode
block|; }
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|template
operator|<
name|class
name|T
operator|>
name|class
name|OnScreenWidget
operator|:
name|public
name|T
block|{
name|public
operator|:
expr|enum
name|ViewMode
block|{
name|RenderView
block|,
name|BaselineView
block|,
name|DifferenceView
block|}
block|;
name|OnScreenWidget
argument_list|(
specifier|const
name|QString
operator|&
name|file
argument_list|,
name|QWidget
operator|*
name|parent
operator|=
literal|0
argument_list|)
operator|:
name|T
argument_list|(
name|parent
argument_list|)
block|,
name|m_filename
argument_list|(
name|file
argument_list|)
block|,
name|m_view_mode
argument_list|(
argument|RenderView
argument_list|)
block|{
name|QSettings
name|settings
argument_list|(
literal|"QtProject"
argument_list|,
literal|"lance"
argument_list|)
block|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
literal|10
condition|;
operator|++
name|i
control|)
block|{
name|QPointF
name|suggestion
argument_list|(
literal|100
operator|+
name|i
operator|*
literal|40
argument_list|,
literal|100
operator|+
literal|100
operator|*
name|qSin
argument_list|(
name|i
operator|*
literal|3.1415
operator|/
literal|10.0
argument_list|)
argument_list|)
decl_stmt|;
name|m_controlPoints
operator|<<
name|settings
operator|.
name|value
argument_list|(
literal|"cp"
operator|+
name|QString
operator|::
name|number
argument_list|(
name|i
argument_list|)
argument_list|,
name|suggestion
argument_list|)
operator|.
name|toPointF
argument_list|()
expr_stmt|;
block|}
name|m_currentPoint
operator|=
operator|-
literal|1
block|;
name|m_showControlPoints
operator|=
name|false
block|;
name|m_deviceType
operator|=
name|WidgetType
block|;
name|m_checkersBackground
operator|=
name|true
block|;
name|m_verboseMode
operator|=
name|false
block|;
name|m_baseline_name
operator|=
name|QString
argument_list|(
name|m_filename
argument_list|)
operator|.
name|replace
argument_list|(
literal|".qps"
argument_list|,
literal|"_qps"
argument_list|)
operator|+
literal|".png"
block|;
if|if
condition|(
name|QFileInfo
argument_list|(
name|m_baseline_name
argument_list|)
operator|.
name|exists
argument_list|()
condition|)
block|{
name|m_baseline
operator|=
name|QPixmap
argument_list|(
name|m_baseline_name
argument_list|)
expr_stmt|;
block|}
end_expr_stmt
begin_if
if|if
condition|(
name|m_baseline
operator|.
name|isNull
argument_list|()
condition|)
block|{
name|T
operator|::
name|setWindowTitle
argument_list|(
literal|"Rendering: '"
operator|+
name|file
operator|+
literal|"'. No baseline available"
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|T
operator|::
name|setWindowTitle
argument_list|(
literal|"Rendering: '"
operator|+
name|file
operator|+
literal|"'. Shortcuts: 1=render, 2=baseline, 3=difference"
argument_list|)
expr_stmt|;
name|StupidWorkaround
modifier|*
name|workaround
init|=
name|new
name|StupidWorkaround
argument_list|(
name|this
argument_list|,
operator|&
name|m_view_mode
argument_list|)
decl_stmt|;
name|QSignalMapper
modifier|*
name|mapper
init|=
name|new
name|QSignalMapper
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|T
operator|::
name|connect
argument_list|(
name|mapper
argument_list|,
name|SIGNAL
argument_list|(
name|mapped
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|,
name|workaround
argument_list|,
name|SLOT
argument_list|(
name|setViewMode
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|T
operator|::
name|connect
argument_list|(
name|mapper
argument_list|,
name|SIGNAL
argument_list|(
name|mapped
argument_list|(
name|QString
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|setWindowTitle
argument_list|(
name|QString
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|QAction
modifier|*
name|renderViewAction
init|=
name|new
name|QAction
argument_list|(
literal|"Render View"
argument_list|,
name|this
argument_list|)
decl_stmt|;
name|renderViewAction
operator|->
name|setShortcut
argument_list|(
name|Qt
operator|::
name|Key_1
argument_list|)
expr_stmt|;
name|T
operator|::
name|connect
argument_list|(
name|renderViewAction
argument_list|,
name|SIGNAL
argument_list|(
name|triggered
argument_list|()
argument_list|)
argument_list|,
name|mapper
argument_list|,
name|SLOT
argument_list|(
name|map
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|mapper
operator|->
name|setMapping
argument_list|(
name|renderViewAction
argument_list|,
name|RenderView
argument_list|)
expr_stmt|;
name|mapper
operator|->
name|setMapping
argument_list|(
name|renderViewAction
argument_list|,
literal|"Render View: "
operator|+
name|file
argument_list|)
expr_stmt|;
name|T
operator|::
name|addAction
argument_list|(
name|renderViewAction
argument_list|)
expr_stmt|;
name|QAction
modifier|*
name|baselineAction
init|=
name|new
name|QAction
argument_list|(
literal|"Baseline"
argument_list|,
name|this
argument_list|)
decl_stmt|;
name|baselineAction
operator|->
name|setShortcut
argument_list|(
name|Qt
operator|::
name|Key_2
argument_list|)
expr_stmt|;
name|T
operator|::
name|connect
argument_list|(
name|baselineAction
argument_list|,
name|SIGNAL
argument_list|(
name|triggered
argument_list|()
argument_list|)
argument_list|,
name|mapper
argument_list|,
name|SLOT
argument_list|(
name|map
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|mapper
operator|->
name|setMapping
argument_list|(
name|baselineAction
argument_list|,
name|BaselineView
argument_list|)
expr_stmt|;
name|mapper
operator|->
name|setMapping
argument_list|(
name|baselineAction
argument_list|,
literal|"Baseline View: "
operator|+
name|file
argument_list|)
expr_stmt|;
name|T
operator|::
name|addAction
argument_list|(
name|baselineAction
argument_list|)
expr_stmt|;
name|QAction
modifier|*
name|differenceAction
init|=
name|new
name|QAction
argument_list|(
literal|"Differenfe View"
argument_list|,
name|this
argument_list|)
decl_stmt|;
name|differenceAction
operator|->
name|setShortcut
argument_list|(
name|Qt
operator|::
name|Key_3
argument_list|)
expr_stmt|;
name|T
operator|::
name|connect
argument_list|(
name|differenceAction
argument_list|,
name|SIGNAL
argument_list|(
name|triggered
argument_list|()
argument_list|)
argument_list|,
name|mapper
argument_list|,
name|SLOT
argument_list|(
name|map
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|mapper
operator|->
name|setMapping
argument_list|(
name|differenceAction
argument_list|,
name|DifferenceView
argument_list|)
expr_stmt|;
name|mapper
operator|->
name|setMapping
argument_list|(
name|differenceAction
argument_list|,
literal|"Difference View"
operator|+
name|file
argument_list|)
expr_stmt|;
name|T
operator|::
name|addAction
argument_list|(
name|differenceAction
argument_list|)
expr_stmt|;
block|}
end_if
begin_macro
unit|}      ~
name|OnScreenWidget
argument_list|()
end_macro
begin_block
block|{
name|QSettings
name|settings
argument_list|(
literal|"QtProject"
argument_list|,
literal|"lance"
argument_list|)
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
literal|10
condition|;
operator|++
name|i
control|)
block|{
name|settings
operator|.
name|setValue
argument_list|(
literal|"cp"
operator|+
name|QString
operator|::
name|number
argument_list|(
name|i
argument_list|)
argument_list|,
name|m_controlPoints
operator|.
name|at
argument_list|(
name|i
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|settings
operator|.
name|sync
argument_list|()
expr_stmt|;
block|}
end_block
begin_function
name|void
name|setVerboseMode
parameter_list|(
name|bool
name|v
parameter_list|)
block|{
name|m_verboseMode
operator|=
name|v
expr_stmt|;
block|}
end_function
begin_function
name|void
name|setCheckersBackground
parameter_list|(
name|bool
name|b
parameter_list|)
block|{
name|m_checkersBackground
operator|=
name|b
expr_stmt|;
block|}
end_function
begin_function
name|void
name|setType
parameter_list|(
name|DeviceType
name|t
parameter_list|)
block|{
name|m_deviceType
operator|=
name|t
expr_stmt|;
block|}
end_function
begin_function
name|void
name|resizeEvent
parameter_list|(
name|QResizeEvent
modifier|*
name|e
parameter_list|)
block|{
name|m_image
operator|=
name|QImage
argument_list|()
expr_stmt|;
name|T
operator|::
name|resizeEvent
argument_list|(
name|e
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
name|void
name|paintEvent
parameter_list|(
name|QPaintEvent
modifier|*
parameter_list|)
block|{
switch|switch
condition|(
name|m_view_mode
condition|)
block|{
case|case
name|RenderView
case|:
name|paintRenderView
argument_list|()
expr_stmt|;
break|break;
case|case
name|BaselineView
case|:
name|paintBaselineView
argument_list|()
expr_stmt|;
break|break;
case|case
name|DifferenceView
case|:
name|paintDifferenceView
argument_list|()
expr_stmt|;
break|break;
block|}
block|}
end_function
begin_function
name|void
name|paintRenderView
parameter_list|()
block|{
name|QPainter
name|pt
decl_stmt|;
name|QPaintDevice
modifier|*
name|dev
init|=
name|this
decl_stmt|;
if|if
condition|(
name|m_deviceType
operator|==
name|ImageWidgetType
condition|)
block|{
if|if
condition|(
name|m_image
operator|.
name|size
argument_list|()
operator|!=
name|T
operator|::
name|size
argument_list|()
condition|)
name|m_image
operator|=
name|QImage
argument_list|(
name|T
operator|::
name|size
argument_list|()
argument_list|,
name|QImage
operator|::
name|Format_ARGB32_Premultiplied
argument_list|)
expr_stmt|;
name|m_image
operator|.
name|fill
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|dev
operator|=
operator|&
name|m_image
expr_stmt|;
block|}
name|pt
operator|.
name|begin
argument_list|(
name|dev
argument_list|)
expr_stmt|;
name|PaintCommands
name|paintCommands
argument_list|(
name|m_commands
argument_list|,
literal|800
argument_list|,
literal|800
argument_list|)
decl_stmt|;
name|paintCommands
operator|.
name|setVerboseMode
argument_list|(
name|m_verboseMode
argument_list|)
expr_stmt|;
name|paintCommands
operator|.
name|setCheckersBackground
argument_list|(
name|m_checkersBackground
argument_list|)
expr_stmt|;
name|paintCommands
operator|.
name|setType
argument_list|(
name|m_deviceType
argument_list|)
expr_stmt|;
name|paintCommands
operator|.
name|setPainter
argument_list|(
operator|&
name|pt
argument_list|)
expr_stmt|;
name|paintCommands
operator|.
name|setControlPoints
argument_list|(
name|m_controlPoints
argument_list|)
expr_stmt|;
name|paintCommands
operator|.
name|setFilePath
argument_list|(
name|QFileInfo
argument_list|(
name|m_filename
argument_list|)
operator|.
name|absolutePath
argument_list|()
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|DO_QWS_DEBUGGING
name|qt_show_painter_debug_output
operator|=
name|true
expr_stmt|;
endif|#
directive|endif
name|pt
operator|.
name|save
argument_list|()
expr_stmt|;
name|paintCommands
operator|.
name|runCommands
argument_list|()
expr_stmt|;
name|pt
operator|.
name|restore
argument_list|()
expr_stmt|;
ifdef|#
directive|ifdef
name|DO_QWS_DEBUGGING
name|qt_show_painter_debug_output
operator|=
name|false
expr_stmt|;
endif|#
directive|endif
name|pt
operator|.
name|end
argument_list|()
expr_stmt|;
if|if
condition|(
name|m_deviceType
operator|==
name|ImageWidgetType
condition|)
block|{
name|QPainter
argument_list|(
name|this
argument_list|)
operator|.
name|drawImage
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|m_image
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|m_currentPoint
operator|>=
literal|0
operator|||
name|m_showControlPoints
condition|)
block|{
name|pt
operator|.
name|begin
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|pt
operator|.
name|setRenderHint
argument_list|(
name|QPainter
operator|::
name|Antialiasing
argument_list|)
expr_stmt|;
name|pt
operator|.
name|setFont
argument_list|(
name|this
operator|->
name|font
argument_list|()
argument_list|)
expr_stmt|;
name|pt
operator|.
name|resetMatrix
argument_list|()
expr_stmt|;
name|pt
operator|.
name|setPen
argument_list|(
name|QColor
argument_list|(
literal|127
argument_list|,
literal|127
argument_list|,
literal|127
argument_list|,
literal|191
argument_list|)
argument_list|)
expr_stmt|;
name|pt
operator|.
name|setBrush
argument_list|(
name|QColor
argument_list|(
literal|191
argument_list|,
literal|191
argument_list|,
literal|255
argument_list|,
literal|63
argument_list|)
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
name|m_controlPoints
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
name|m_showControlPoints
operator|||
name|m_currentPoint
operator|==
name|i
condition|)
block|{
name|QPointF
name|cp
init|=
name|m_controlPoints
operator|.
name|at
argument_list|(
name|i
argument_list|)
decl_stmt|;
name|QRectF
name|rect
argument_list|(
name|cp
operator|.
name|x
argument_list|()
operator|-
name|CP_RADIUS
argument_list|,
name|cp
operator|.
name|y
argument_list|()
operator|-
name|CP_RADIUS
argument_list|,
name|CP_RADIUS
operator|*
literal|2
argument_list|,
name|CP_RADIUS
operator|*
literal|2
argument_list|)
decl_stmt|;
name|pt
operator|.
name|drawEllipse
argument_list|(
name|rect
argument_list|)
expr_stmt|;
name|pt
operator|.
name|drawText
argument_list|(
name|rect
argument_list|,
name|Qt
operator|::
name|AlignCenter
argument_list|,
name|QString
operator|::
name|number
argument_list|(
name|i
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
block|}
if|#
directive|if
literal|0
comment|// ### TBD: Make this work with Qt5
block|if (m_render_view.isNull()) {             m_render_view = QPixmap::grabWidget(this);             m_render_view.save("renderView.png");         }
endif|#
directive|endif
block|}
end_function
begin_function
name|void
name|paintBaselineView
parameter_list|()
block|{
name|QPainter
name|p
argument_list|(
name|this
argument_list|)
decl_stmt|;
if|if
condition|(
name|m_baseline
operator|.
name|isNull
argument_list|()
condition|)
block|{
name|p
operator|.
name|drawText
argument_list|(
name|T
operator|::
name|rect
argument_list|()
argument_list|,
name|Qt
operator|::
name|AlignCenter
argument_list|,
literal|"No baseline found\n"
literal|"file '"
operator|+
name|m_baseline_name
operator|+
literal|"' does not exist..."
argument_list|)
expr_stmt|;
return|return;
block|}
name|p
operator|.
name|drawPixmap
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|m_baseline
argument_list|)
expr_stmt|;
name|p
operator|.
name|setPen
argument_list|(
name|QColor
operator|::
name|fromRgb
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0.1
argument_list|)
argument_list|)
expr_stmt|;
name|p
operator|.
name|setFont
argument_list|(
name|QFont
argument_list|(
literal|"Arial"
argument_list|,
literal|128
argument_list|)
argument_list|)
expr_stmt|;
name|p
operator|.
name|rotate
argument_list|(
literal|45
argument_list|)
expr_stmt|;
name|p
operator|.
name|drawText
argument_list|(
literal|100
argument_list|,
literal|0
argument_list|,
literal|"BASELINE"
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
name|QPixmap
name|generateDifference
parameter_list|()
block|{
name|QImage
name|img
argument_list|(
name|T
operator|::
name|size
argument_list|()
argument_list|,
name|QImage
operator|::
name|Format_RGB32
argument_list|)
decl_stmt|;
name|img
operator|.
name|fill
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|QPainter
name|p
argument_list|(
operator|&
name|img
argument_list|)
decl_stmt|;
name|p
operator|.
name|drawPixmap
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|m_render_view
argument_list|)
expr_stmt|;
name|p
operator|.
name|setCompositionMode
argument_list|(
name|QPainter
operator|::
name|RasterOp_SourceXorDestination
argument_list|)
expr_stmt|;
name|p
operator|.
name|drawPixmap
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|m_baseline
argument_list|)
expr_stmt|;
name|p
operator|.
name|end
argument_list|()
expr_stmt|;
return|return
name|QPixmap
operator|::
name|fromImage
argument_list|(
name|img
argument_list|)
return|;
block|}
end_function
begin_function
name|void
name|paintDifferenceView
parameter_list|()
block|{
name|QPainter
name|p
argument_list|(
name|this
argument_list|)
decl_stmt|;
if|if
condition|(
name|m_baseline
operator|.
name|isNull
argument_list|()
condition|)
block|{
name|p
operator|.
name|drawText
argument_list|(
name|T
operator|::
name|rect
argument_list|()
argument_list|,
name|Qt
operator|::
name|AlignCenter
argument_list|,
literal|"No baseline found\n"
literal|"file '"
operator|+
name|m_baseline_name
operator|+
literal|"' does not exist..."
argument_list|)
expr_stmt|;
return|return;
block|}
name|p
operator|.
name|fillRect
argument_list|(
name|T
operator|::
name|rect
argument_list|()
argument_list|,
name|Qt
operator|::
name|black
argument_list|)
expr_stmt|;
name|p
operator|.
name|drawPixmap
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|generateDifference
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
name|void
name|mouseMoveEvent
parameter_list|(
name|QMouseEvent
modifier|*
name|e
parameter_list|)
block|{
if|if
condition|(
name|m_currentPoint
operator|==
operator|-
literal|1
condition|)
return|return;
if|if
condition|(
name|T
operator|::
name|rect
argument_list|()
operator|.
name|contains
argument_list|(
name|e
operator|->
name|pos
argument_list|()
argument_list|)
condition|)
name|m_controlPoints
index|[
name|m_currentPoint
index|]
operator|=
name|e
operator|->
name|pos
argument_list|()
expr_stmt|;
name|T
operator|::
name|update
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
name|void
name|mousePressEvent
parameter_list|(
name|QMouseEvent
modifier|*
name|e
parameter_list|)
block|{
if|if
condition|(
name|e
operator|->
name|button
argument_list|()
operator|==
name|Qt
operator|::
name|RightButton
condition|)
block|{
name|m_showControlPoints
operator|=
name|true
expr_stmt|;
block|}
if|if
condition|(
name|e
operator|->
name|button
argument_list|()
operator|==
name|Qt
operator|::
name|LeftButton
condition|)
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|m_controlPoints
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
name|QLineF
argument_list|(
name|m_controlPoints
operator|.
name|at
argument_list|(
name|i
argument_list|)
argument_list|,
name|e
operator|->
name|pos
argument_list|()
argument_list|)
operator|.
name|length
argument_list|()
operator|<
name|CP_RADIUS
condition|)
block|{
name|m_currentPoint
operator|=
name|i
expr_stmt|;
break|break;
block|}
block|}
block|}
name|T
operator|::
name|update
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
name|void
name|mouseReleaseEvent
parameter_list|(
name|QMouseEvent
modifier|*
name|e
parameter_list|)
block|{
if|if
condition|(
name|e
operator|->
name|button
argument_list|()
operator|==
name|Qt
operator|::
name|LeftButton
condition|)
name|m_currentPoint
operator|=
operator|-
literal|1
expr_stmt|;
if|if
condition|(
name|e
operator|->
name|button
argument_list|()
operator|==
name|Qt
operator|::
name|RightButton
condition|)
name|m_showControlPoints
operator|=
name|false
expr_stmt|;
name|T
operator|::
name|update
argument_list|()
expr_stmt|;
block|}
end_function
begin_expr_stmt
name|QSize
name|sizeHint
argument_list|()
specifier|const
block|{
return|return
name|QSize
argument_list|(
literal|800
argument_list|,
literal|800
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|QVector
operator|<
name|QPointF
operator|>
name|m_controlPoints
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|int
name|m_currentPoint
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|bool
name|m_showControlPoints
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QStringList
name|m_commands
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QString
name|m_filename
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QString
name|m_baseline_name
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|bool
name|m_verboseMode
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|bool
name|m_checkersBackground
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|DeviceType
name|m_deviceType
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|int
name|m_view_mode
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QImage
name|m_image
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QPixmap
name|m_baseline
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QPixmap
name|m_render_view
decl_stmt|;
end_decl_stmt
begin_endif
unit|};
endif|#
directive|endif
end_endif
end_unit
