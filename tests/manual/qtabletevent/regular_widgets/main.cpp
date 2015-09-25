begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QApplication>
end_include
begin_include
include|#
directive|include
file|<QDebug>
end_include
begin_include
include|#
directive|include
file|<QMouseEvent>
end_include
begin_include
include|#
directive|include
file|<QTabletEvent>
end_include
begin_include
include|#
directive|include
file|<QMainWindow>
end_include
begin_include
include|#
directive|include
file|<QMenuBar>
end_include
begin_include
include|#
directive|include
file|<QMenu>
end_include
begin_include
include|#
directive|include
file|<QAction>
end_include
begin_include
include|#
directive|include
file|<QStatusBar>
end_include
begin_include
include|#
directive|include
file|<QVector>
end_include
begin_include
include|#
directive|include
file|<QPainter>
end_include
begin_include
include|#
directive|include
file|<QCursor>
end_include
begin_enum
DECL|enum|TabletPointType
enum|enum
name|TabletPointType
block|{
DECL|enumerator|TabletButtonPress
name|TabletButtonPress
block|,
DECL|enumerator|TabletButtonRelease
name|TabletButtonRelease
block|,
DECL|enumerator|TabletMove
name|TabletMove
block|}
enum|;
end_enum
begin_struct
DECL|struct|TabletPoint
struct|struct
name|TabletPoint
block|{
DECL|function|TabletPoint
name|TabletPoint
parameter_list|(
specifier|const
name|QPointF
modifier|&
name|p
init|=
name|QPointF
argument_list|()
parameter_list|,
name|TabletPointType
name|t
init|=
name|TabletMove
parameter_list|,
name|Qt
operator|::
name|MouseButton
name|b
init|=
name|Qt
operator|::
name|LeftButton
parameter_list|,
name|QTabletEvent
operator|::
name|PointerType
name|pt
init|=
name|QTabletEvent
operator|::
name|UnknownPointer
parameter_list|,
name|qreal
name|prs
init|=
literal|0
parameter_list|,
name|qreal
name|rotation
init|=
literal|0
parameter_list|)
member_init_list|:
name|pos
argument_list|(
name|p
argument_list|)
member_init_list|,
name|type
argument_list|(
name|t
argument_list|)
member_init_list|,
name|button
argument_list|(
name|b
argument_list|)
member_init_list|,
name|ptype
argument_list|(
name|pt
argument_list|)
member_init_list|,
name|pressure
argument_list|(
name|prs
argument_list|)
member_init_list|,
name|angle
argument_list|(
name|rotation
argument_list|)
block|{}
DECL|member|pos
name|QPointF
name|pos
decl_stmt|;
DECL|member|type
name|TabletPointType
name|type
decl_stmt|;
DECL|member|button
name|Qt
operator|::
name|MouseButton
name|button
decl_stmt|;
DECL|member|ptype
name|QTabletEvent
operator|::
name|PointerType
name|ptype
decl_stmt|;
DECL|member|pressure
name|qreal
name|pressure
decl_stmt|;
DECL|member|angle
name|qreal
name|angle
decl_stmt|;
block|}
struct|;
end_struct
begin_class
DECL|class|EventReportWidget
class|class
name|EventReportWidget
super|:
specifier|public
name|QWidget
block|{
name|Q_OBJECT
public|public:
name|EventReportWidget
parameter_list|()
constructor_decl|;
public|public
name|slots
public|:
DECL|function|clearPoints
name|void
name|clearPoints
parameter_list|()
block|{
name|m_points
operator|.
name|clear
argument_list|()
expr_stmt|;
name|update
argument_list|()
expr_stmt|;
block|}
signals|signals:
name|void
name|stats
parameter_list|(
name|QString
name|s
parameter_list|)
function_decl|;
protected|protected:
DECL|function|mouseDoubleClickEvent
name|void
name|mouseDoubleClickEvent
parameter_list|(
name|QMouseEvent
modifier|*
name|event
parameter_list|)
block|{
name|outputMouseEvent
argument_list|(
name|event
argument_list|)
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
name|outputMouseEvent
argument_list|(
name|event
argument_list|)
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
name|outputMouseEvent
argument_list|(
name|event
argument_list|)
expr_stmt|;
block|}
DECL|function|mouseReleaseEvent
name|void
name|mouseReleaseEvent
parameter_list|(
name|QMouseEvent
modifier|*
name|event
parameter_list|)
block|{
name|outputMouseEvent
argument_list|(
name|event
argument_list|)
expr_stmt|;
block|}
name|void
name|tabletEvent
parameter_list|(
name|QTabletEvent
modifier|*
parameter_list|)
function_decl|;
name|void
name|paintEvent
parameter_list|(
name|QPaintEvent
modifier|*
parameter_list|)
function_decl|;
name|void
name|timerEvent
parameter_list|(
name|QTimerEvent
modifier|*
parameter_list|)
function_decl|;
private|private:
name|void
name|outputMouseEvent
parameter_list|(
name|QMouseEvent
modifier|*
name|event
parameter_list|)
function_decl|;
DECL|member|m_lastIsMouseMove
name|bool
name|m_lastIsMouseMove
decl_stmt|;
DECL|member|m_lastIsTabletMove
name|bool
name|m_lastIsTabletMove
decl_stmt|;
DECL|member|m_lastButton
name|Qt
operator|::
name|MouseButton
name|m_lastButton
decl_stmt|;
DECL|member|m_points
name|QVector
argument_list|<
name|TabletPoint
argument_list|>
name|m_points
decl_stmt|;
DECL|member|m_tabletMoveCount
name|int
name|m_tabletMoveCount
decl_stmt|;
DECL|member|m_paintEventCount
name|int
name|m_paintEventCount
decl_stmt|;
block|}
class|;
end_class
begin_constructor
DECL|function|EventReportWidget
name|EventReportWidget
operator|::
name|EventReportWidget
parameter_list|()
member_init_list|:
name|m_lastIsMouseMove
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|m_lastIsTabletMove
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|m_lastButton
argument_list|(
name|Qt
operator|::
name|NoButton
argument_list|)
member_init_list|,
name|m_tabletMoveCount
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|m_paintEventCount
argument_list|(
literal|0
argument_list|)
block|{
name|startTimer
argument_list|(
literal|1000
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|paintEvent
name|void
name|EventReportWidget
operator|::
name|paintEvent
parameter_list|(
name|QPaintEvent
modifier|*
parameter_list|)
block|{
name|QPainter
name|p
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|int
name|lineSpacing
init|=
name|fontMetrics
argument_list|()
operator|.
name|lineSpacing
argument_list|()
decl_stmt|;
name|int
name|halfLineSpacing
init|=
name|lineSpacing
operator|/
literal|2
decl_stmt|;
specifier|const
name|QRectF
name|geom
init|=
name|QRectF
argument_list|(
name|QPoint
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|,
name|size
argument_list|()
argument_list|)
decl_stmt|;
name|p
operator|.
name|fillRect
argument_list|(
name|geom
argument_list|,
name|Qt
operator|::
name|white
argument_list|)
expr_stmt|;
name|p
operator|.
name|drawRect
argument_list|(
name|QRectF
argument_list|(
name|geom
operator|.
name|topLeft
argument_list|()
argument_list|,
name|geom
operator|.
name|bottomRight
argument_list|()
operator|-
name|QPointF
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|p
operator|.
name|setPen
argument_list|(
name|Qt
operator|::
name|white
argument_list|)
expr_stmt|;
name|QPainterPath
name|ellipse
decl_stmt|;
name|ellipse
operator|.
name|addEllipse
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|halfLineSpacing
operator|*
literal|5
argument_list|,
name|halfLineSpacing
argument_list|)
expr_stmt|;
foreach|foreach
control|(
specifier|const
name|TabletPoint
modifier|&
name|t
decl|,
name|m_points
control|)
block|{
if|if
condition|(
name|geom
operator|.
name|contains
argument_list|(
name|t
operator|.
name|pos
argument_list|)
condition|)
block|{
name|QPainterPath
name|pp
decl_stmt|;
name|pp
operator|.
name|addEllipse
argument_list|(
name|t
operator|.
name|pos
argument_list|,
name|halfLineSpacing
argument_list|,
name|halfLineSpacing
argument_list|)
expr_stmt|;
name|QRectF
name|pointBounds
argument_list|(
name|t
operator|.
name|pos
operator|.
name|x
argument_list|()
operator|-
name|halfLineSpacing
argument_list|,
name|t
operator|.
name|pos
operator|.
name|y
argument_list|()
operator|-
name|halfLineSpacing
argument_list|,
name|lineSpacing
argument_list|,
name|lineSpacing
argument_list|)
decl_stmt|;
switch|switch
condition|(
name|t
operator|.
name|type
condition|)
block|{
case|case
name|TabletButtonPress
case|:
name|p
operator|.
name|fillPath
argument_list|(
name|pp
argument_list|,
name|Qt
operator|::
name|darkGreen
argument_list|)
expr_stmt|;
if|if
condition|(
name|t
operator|.
name|button
operator|!=
name|Qt
operator|::
name|NoButton
condition|)
name|p
operator|.
name|drawText
argument_list|(
name|pointBounds
argument_list|,
name|Qt
operator|::
name|AlignCenter
argument_list|,
name|QString
operator|::
name|number
argument_list|(
name|t
operator|.
name|button
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|TabletButtonRelease
case|:
name|p
operator|.
name|fillPath
argument_list|(
name|pp
argument_list|,
name|Qt
operator|::
name|red
argument_list|)
expr_stmt|;
if|if
condition|(
name|t
operator|.
name|button
operator|!=
name|Qt
operator|::
name|NoButton
condition|)
name|p
operator|.
name|drawText
argument_list|(
name|pointBounds
argument_list|,
name|Qt
operator|::
name|AlignCenter
argument_list|,
name|QString
operator|::
name|number
argument_list|(
name|t
operator|.
name|button
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|TabletMove
case|:
if|if
condition|(
name|t
operator|.
name|pressure
operator|>
literal|0.0
condition|)
block|{
name|p
operator|.
name|setPen
argument_list|(
name|t
operator|.
name|ptype
operator|==
name|QTabletEvent
operator|::
name|Eraser
condition|?
name|Qt
operator|::
name|red
else|:
name|Qt
operator|::
name|black
argument_list|)
expr_stmt|;
if|if
condition|(
name|t
operator|.
name|angle
operator|!=
literal|0.0
condition|)
block|{
name|p
operator|.
name|save
argument_list|()
expr_stmt|;
name|p
operator|.
name|translate
argument_list|(
name|t
operator|.
name|pos
argument_list|)
expr_stmt|;
name|p
operator|.
name|scale
argument_list|(
name|t
operator|.
name|pressure
argument_list|,
name|t
operator|.
name|pressure
argument_list|)
expr_stmt|;
name|p
operator|.
name|rotate
argument_list|(
name|t
operator|.
name|angle
argument_list|)
expr_stmt|;
name|p
operator|.
name|drawPath
argument_list|(
name|ellipse
argument_list|)
expr_stmt|;
name|p
operator|.
name|restore
argument_list|()
expr_stmt|;
block|}
else|else
block|{
name|p
operator|.
name|drawEllipse
argument_list|(
name|t
operator|.
name|pos
argument_list|,
name|t
operator|.
name|pressure
operator|*
name|halfLineSpacing
argument_list|,
name|t
operator|.
name|pressure
operator|*
name|halfLineSpacing
argument_list|)
expr_stmt|;
block|}
name|p
operator|.
name|setPen
argument_list|(
name|Qt
operator|::
name|white
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|p
operator|.
name|fillRect
argument_list|(
name|t
operator|.
name|pos
operator|.
name|x
argument_list|()
operator|-
literal|2
argument_list|,
name|t
operator|.
name|pos
operator|.
name|y
argument_list|()
operator|-
literal|2
argument_list|,
literal|4
argument_list|,
literal|4
argument_list|,
name|Qt
operator|::
name|black
argument_list|)
expr_stmt|;
block|}
break|break;
block|}
block|}
block|}
operator|++
name|m_paintEventCount
expr_stmt|;
block|}
end_function
begin_function
DECL|function|tabletEvent
name|void
name|EventReportWidget
operator|::
name|tabletEvent
parameter_list|(
name|QTabletEvent
modifier|*
name|event
parameter_list|)
block|{
name|QWidget
operator|::
name|tabletEvent
argument_list|(
name|event
argument_list|)
expr_stmt|;
name|bool
name|isMove
init|=
literal|false
decl_stmt|;
switch|switch
condition|(
name|event
operator|->
name|type
argument_list|()
condition|)
block|{
case|case
name|QEvent
operator|::
name|TabletEnterProximity
case|:
case|case
name|QEvent
operator|::
name|TabletLeaveProximity
case|:
name|qDebug
argument_list|()
operator|<<
literal|"proximity"
operator|<<
name|event
expr_stmt|;
break|break;
case|case
name|QEvent
operator|::
name|TabletMove
case|:
name|m_points
operator|.
name|push_back
argument_list|(
name|TabletPoint
argument_list|(
name|event
operator|->
name|pos
argument_list|()
argument_list|,
name|TabletMove
argument_list|,
name|m_lastButton
argument_list|,
name|event
operator|->
name|pointerType
argument_list|()
argument_list|,
name|event
operator|->
name|pressure
argument_list|()
argument_list|,
name|event
operator|->
name|rotation
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|update
argument_list|()
expr_stmt|;
name|isMove
operator|=
literal|true
expr_stmt|;
operator|++
name|m_tabletMoveCount
expr_stmt|;
break|break;
case|case
name|QEvent
operator|::
name|TabletPress
case|:
name|m_points
operator|.
name|push_back
argument_list|(
name|TabletPoint
argument_list|(
name|event
operator|->
name|pos
argument_list|()
argument_list|,
name|TabletButtonPress
argument_list|,
name|event
operator|->
name|button
argument_list|()
argument_list|,
name|event
operator|->
name|pointerType
argument_list|()
argument_list|,
name|event
operator|->
name|rotation
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|m_lastButton
operator|=
name|event
operator|->
name|button
argument_list|()
expr_stmt|;
name|update
argument_list|()
expr_stmt|;
break|break;
case|case
name|QEvent
operator|::
name|TabletRelease
case|:
name|m_points
operator|.
name|push_back
argument_list|(
name|TabletPoint
argument_list|(
name|event
operator|->
name|pos
argument_list|()
argument_list|,
name|TabletButtonRelease
argument_list|,
name|event
operator|->
name|button
argument_list|()
argument_list|,
name|event
operator|->
name|pointerType
argument_list|()
argument_list|,
name|event
operator|->
name|rotation
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|update
argument_list|()
expr_stmt|;
break|break;
default|default:
name|Q_ASSERT
argument_list|(
literal|false
argument_list|)
expr_stmt|;
break|break;
block|}
if|if
condition|(
operator|!
operator|(
name|isMove
operator|&&
name|m_lastIsTabletMove
operator|)
condition|)
block|{
name|QDebug
name|d
init|=
name|qDebug
argument_list|()
decl_stmt|;
name|d
operator|<<
name|event
operator|<<
literal|" global position = "
operator|<<
name|event
operator|->
name|globalPos
argument_list|()
operator|<<
literal|" cursor at "
operator|<<
name|QCursor
operator|::
name|pos
argument_list|()
expr_stmt|;
if|if
condition|(
name|event
operator|->
name|button
argument_list|()
operator|!=
name|Qt
operator|::
name|NoButton
condition|)
name|d
operator|<<
literal|" changed button "
operator|<<
name|event
operator|->
name|button
argument_list|()
expr_stmt|;
block|}
name|m_lastIsTabletMove
operator|=
name|isMove
expr_stmt|;
block|}
end_function
begin_function
DECL|function|outputMouseEvent
name|void
name|EventReportWidget
operator|::
name|outputMouseEvent
parameter_list|(
name|QMouseEvent
modifier|*
name|event
parameter_list|)
block|{
if|if
condition|(
name|event
operator|->
name|type
argument_list|()
operator|==
name|QEvent
operator|::
name|MouseMove
condition|)
block|{
if|if
condition|(
name|m_lastIsMouseMove
condition|)
return|return;
comment|// only show one move to keep things readable
name|m_lastIsMouseMove
operator|=
literal|true
expr_stmt|;
block|}
name|qDebug
argument_list|()
operator|<<
name|event
expr_stmt|;
block|}
end_function
begin_function
DECL|function|timerEvent
name|void
name|EventReportWidget
operator|::
name|timerEvent
parameter_list|(
name|QTimerEvent
modifier|*
parameter_list|)
block|{
emit|emit
name|stats
argument_list|(
name|QString
argument_list|(
literal|"%1 moves/sec, %2 frames/sec"
argument_list|)
operator|.
name|arg
argument_list|(
name|m_tabletMoveCount
argument_list|)
operator|.
name|arg
argument_list|(
name|m_paintEventCount
argument_list|)
argument_list|)
emit|;
name|m_tabletMoveCount
operator|=
literal|0
expr_stmt|;
name|m_paintEventCount
operator|=
literal|0
expr_stmt|;
block|}
end_function
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
name|argv
index|[]
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
name|QMainWindow
name|mainWindow
decl_stmt|;
name|mainWindow
operator|.
name|setWindowTitle
argument_list|(
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"Tablet Test %1"
argument_list|)
operator|.
name|arg
argument_list|(
name|QT_VERSION_STR
argument_list|)
argument_list|)
expr_stmt|;
name|EventReportWidget
modifier|*
name|widget
init|=
operator|new
name|EventReportWidget
decl_stmt|;
name|widget
operator|->
name|setMinimumSize
argument_list|(
literal|640
argument_list|,
literal|480
argument_list|)
expr_stmt|;
name|QMenu
modifier|*
name|fileMenu
init|=
name|mainWindow
operator|.
name|menuBar
argument_list|()
operator|->
name|addMenu
argument_list|(
literal|"File"
argument_list|)
decl_stmt|;
name|QObject
operator|::
name|connect
argument_list|(
name|fileMenu
operator|->
name|addAction
argument_list|(
literal|"Clear"
argument_list|)
argument_list|,
name|SIGNAL
argument_list|(
name|triggered
argument_list|()
argument_list|)
argument_list|,
name|widget
argument_list|,
name|SLOT
argument_list|(
name|clearPoints
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|QObject
operator|::
name|connect
argument_list|(
name|widget
argument_list|,
name|SIGNAL
argument_list|(
name|stats
argument_list|(
name|QString
argument_list|)
argument_list|)
argument_list|,
name|mainWindow
operator|.
name|statusBar
argument_list|()
argument_list|,
name|SLOT
argument_list|(
name|showMessage
argument_list|(
name|QString
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|QAction
modifier|*
name|quitAction
init|=
name|fileMenu
operator|->
name|addAction
argument_list|(
literal|"Quit"
argument_list|)
decl_stmt|;
name|QObject
operator|::
name|connect
argument_list|(
name|quitAction
argument_list|,
name|SIGNAL
argument_list|(
name|triggered
argument_list|()
argument_list|)
argument_list|,
name|qApp
argument_list|,
name|SLOT
argument_list|(
name|quit
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|quitAction
operator|->
name|setShortcut
argument_list|(
name|Qt
operator|::
name|CTRL
operator|+
name|Qt
operator|::
name|Key_Q
argument_list|)
expr_stmt|;
name|mainWindow
operator|.
name|setCentralWidget
argument_list|(
name|widget
argument_list|)
expr_stmt|;
name|mainWindow
operator|.
name|show
argument_list|()
expr_stmt|;
return|return
name|app
operator|.
name|exec
argument_list|()
return|;
block|}
end_function
begin_include
include|#
directive|include
file|"main.moc"
end_include
end_unit
