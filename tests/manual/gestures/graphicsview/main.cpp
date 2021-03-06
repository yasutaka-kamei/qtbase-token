begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QApplication>
end_include
begin_include
include|#
directive|include
file|<QMainWindow>
end_include
begin_include
include|#
directive|include
file|<QGraphicsScene>
end_include
begin_include
include|#
directive|include
file|<QGraphicsView>
end_include
begin_include
include|#
directive|include
file|<QScrollBar>
end_include
begin_include
include|#
directive|include
file|<QImageReader>
end_include
begin_include
include|#
directive|include
file|<QVBoxLayout>
end_include
begin_include
include|#
directive|include
file|<QGestureEvent>
end_include
begin_include
include|#
directive|include
file|<QDir>
end_include
begin_include
include|#
directive|include
file|<QFileDialog>
end_include
begin_include
include|#
directive|include
file|"imageitem.h"
end_include
begin_include
include|#
directive|include
file|"gestures.h"
end_include
begin_include
include|#
directive|include
file|"mousepangesturerecognizer.h"
end_include
begin_class
DECL|class|GraphicsView
class|class
name|GraphicsView
super|:
specifier|public
name|QGraphicsView
block|{
public|public:
DECL|function|GraphicsView
name|GraphicsView
parameter_list|(
name|QGraphicsScene
modifier|*
name|scene
parameter_list|,
name|QWidget
modifier|*
name|parent
init|=
literal|0
parameter_list|)
member_init_list|:
name|QGraphicsView
argument_list|(
name|scene
argument_list|,
name|parent
argument_list|)
block|{     }
protected|protected:
DECL|function|viewportEvent
name|bool
name|viewportEvent
parameter_list|(
name|QEvent
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
name|Gesture
condition|)
block|{
name|QGestureEvent
modifier|*
name|ge
init|=
cast|static_cast
argument_list|<
name|QGestureEvent
operator|*
argument_list|>
argument_list|(
name|event
argument_list|)
decl_stmt|;
if|if
condition|(
name|QPanGesture
modifier|*
name|pan
init|=
cast|static_cast
argument_list|<
name|QPanGesture
operator|*
argument_list|>
argument_list|(
name|ge
operator|->
name|gesture
argument_list|(
name|Qt
operator|::
name|PanGesture
argument_list|)
argument_list|)
condition|)
block|{
switch|switch
condition|(
name|pan
operator|->
name|state
argument_list|()
condition|)
block|{
case|case
name|Qt
operator|::
name|GestureStarted
case|:
name|qDebug
argument_list|(
literal|"view: Pan: started"
argument_list|)
expr_stmt|;
break|break;
case|case
name|Qt
operator|::
name|GestureFinished
case|:
name|qDebug
argument_list|(
literal|"view: Pan: finished"
argument_list|)
expr_stmt|;
break|break;
case|case
name|Qt
operator|::
name|GestureCanceled
case|:
name|qDebug
argument_list|(
literal|"view: Pan: canceled"
argument_list|)
expr_stmt|;
break|break;
case|case
name|Qt
operator|::
name|GestureUpdated
case|:
break|break;
default|default:
name|qDebug
argument_list|(
literal|"view: Pan:<unknown state>"
argument_list|)
expr_stmt|;
break|break;
block|}
specifier|const
name|QPointF
name|delta
init|=
name|pan
operator|->
name|delta
argument_list|()
decl_stmt|;
name|QScrollBar
modifier|*
name|vbar
init|=
name|verticalScrollBar
argument_list|()
decl_stmt|;
name|QScrollBar
modifier|*
name|hbar
init|=
name|horizontalScrollBar
argument_list|()
decl_stmt|;
name|vbar
operator|->
name|setValue
argument_list|(
name|vbar
operator|->
name|value
argument_list|()
operator|-
name|delta
operator|.
name|y
argument_list|()
argument_list|)
expr_stmt|;
name|hbar
operator|->
name|setValue
argument_list|(
name|hbar
operator|->
name|value
argument_list|()
operator|-
name|delta
operator|.
name|x
argument_list|()
argument_list|)
expr_stmt|;
name|ge
operator|->
name|accept
argument_list|(
name|pan
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
block|}
return|return
name|QGraphicsView
operator|::
name|viewportEvent
argument_list|(
name|event
argument_list|)
return|;
block|}
block|}
class|;
end_class
begin_class
DECL|class|StandardGestures
class|class
name|StandardGestures
super|:
specifier|public
name|QWidget
block|{
public|public:
DECL|function|StandardGestures
name|StandardGestures
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
block|{
name|scene
operator|=
operator|new
name|QGraphicsScene
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|scene
operator|->
name|setSceneRect
argument_list|(
operator|-
literal|2000
argument_list|,
operator|-
literal|2000
argument_list|,
literal|4000
argument_list|,
literal|4000
argument_list|)
expr_stmt|;
name|view
operator|=
operator|new
name|QGraphicsView
argument_list|(
name|scene
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QVBoxLayout
modifier|*
name|l
init|=
operator|new
name|QVBoxLayout
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|l
operator|->
name|addWidget
argument_list|(
name|view
argument_list|)
expr_stmt|;
block|}
DECL|member|scene
name|QGraphicsScene
modifier|*
name|scene
decl_stmt|;
DECL|member|view
name|QGraphicsView
modifier|*
name|view
decl_stmt|;
block|}
class|;
end_class
begin_class
DECL|class|GlobalViewGestures
class|class
name|GlobalViewGestures
super|:
specifier|public
name|QWidget
block|{
name|Q_OBJECT
public|public:
DECL|function|GlobalViewGestures
name|GlobalViewGestures
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
block|{
name|scene
operator|=
operator|new
name|QGraphicsScene
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|scene
operator|->
name|setSceneRect
argument_list|(
operator|-
literal|2000
argument_list|,
operator|-
literal|2000
argument_list|,
literal|4000
argument_list|,
literal|4000
argument_list|)
expr_stmt|;
name|view
operator|=
operator|new
name|GraphicsView
argument_list|(
name|scene
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|view
operator|->
name|viewport
argument_list|()
operator|->
name|grabGesture
argument_list|(
name|Qt
operator|::
name|PanGesture
argument_list|)
expr_stmt|;
name|view
operator|->
name|viewport
argument_list|()
operator|->
name|grabGesture
argument_list|(
name|ThreeFingerSlideGesture
operator|::
name|Type
argument_list|)
expr_stmt|;
name|QVBoxLayout
modifier|*
name|l
init|=
operator|new
name|QVBoxLayout
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|l
operator|->
name|addWidget
argument_list|(
name|view
argument_list|)
expr_stmt|;
block|}
DECL|member|scene
name|QGraphicsScene
modifier|*
name|scene
decl_stmt|;
DECL|member|view
name|QGraphicsView
modifier|*
name|view
decl_stmt|;
block|}
class|;
end_class
begin_class
DECL|class|GraphicsItemGestures
class|class
name|GraphicsItemGestures
super|:
specifier|public
name|QWidget
block|{
name|Q_OBJECT
public|public:
DECL|function|GraphicsItemGestures
name|GraphicsItemGestures
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
block|{
name|scene
operator|=
operator|new
name|QGraphicsScene
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|scene
operator|->
name|setSceneRect
argument_list|(
operator|-
literal|2000
argument_list|,
operator|-
literal|2000
argument_list|,
literal|4000
argument_list|,
literal|4000
argument_list|)
expr_stmt|;
name|view
operator|=
operator|new
name|QGraphicsView
argument_list|(
name|scene
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|view
operator|->
name|viewport
argument_list|()
operator|->
name|grabGesture
argument_list|(
name|Qt
operator|::
name|PanGesture
argument_list|)
expr_stmt|;
name|view
operator|->
name|viewport
argument_list|()
operator|->
name|grabGesture
argument_list|(
name|ThreeFingerSlideGesture
operator|::
name|Type
argument_list|)
expr_stmt|;
name|QVBoxLayout
modifier|*
name|l
init|=
operator|new
name|QVBoxLayout
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|l
operator|->
name|addWidget
argument_list|(
name|view
argument_list|)
expr_stmt|;
block|}
DECL|member|scene
name|QGraphicsScene
modifier|*
name|scene
decl_stmt|;
DECL|member|view
name|QGraphicsView
modifier|*
name|view
decl_stmt|;
block|}
class|;
end_class
begin_class
DECL|class|MainWindow
class|class
name|MainWindow
super|:
specifier|public
name|QMainWindow
block|{
public|public:
name|MainWindow
parameter_list|()
constructor_decl|;
name|void
name|setDirectory
parameter_list|(
specifier|const
name|QString
modifier|&
name|path
parameter_list|)
function_decl|;
private|private:
DECL|member|tabWidget
name|QTabWidget
modifier|*
name|tabWidget
decl_stmt|;
DECL|member|standardGestures
name|StandardGestures
modifier|*
name|standardGestures
decl_stmt|;
DECL|member|globalViewGestures
name|GlobalViewGestures
modifier|*
name|globalViewGestures
decl_stmt|;
DECL|member|graphicsItemGestures
name|GraphicsItemGestures
modifier|*
name|graphicsItemGestures
decl_stmt|;
block|}
class|;
end_class
begin_constructor
DECL|function|MainWindow
name|MainWindow
operator|::
name|MainWindow
parameter_list|()
block|{
operator|(
name|void
operator|)
name|QGestureRecognizer
operator|::
name|registerRecognizer
argument_list|(
operator|new
name|MousePanGestureRecognizer
argument_list|)
expr_stmt|;
name|ThreeFingerSlideGesture
operator|::
name|Type
operator|=
name|QGestureRecognizer
operator|::
name|registerRecognizer
argument_list|(
operator|new
name|ThreeFingerSlideGestureRecognizer
argument_list|)
expr_stmt|;
name|tabWidget
operator|=
operator|new
name|QTabWidget
expr_stmt|;
name|standardGestures
operator|=
operator|new
name|StandardGestures
expr_stmt|;
name|tabWidget
operator|->
name|addTab
argument_list|(
name|standardGestures
argument_list|,
literal|"Standard gestures"
argument_list|)
expr_stmt|;
name|globalViewGestures
operator|=
operator|new
name|GlobalViewGestures
expr_stmt|;
name|tabWidget
operator|->
name|addTab
argument_list|(
name|globalViewGestures
argument_list|,
literal|"Global gestures"
argument_list|)
expr_stmt|;
name|graphicsItemGestures
operator|=
operator|new
name|GraphicsItemGestures
expr_stmt|;
name|tabWidget
operator|->
name|addTab
argument_list|(
name|graphicsItemGestures
argument_list|,
literal|"Graphics item gestures"
argument_list|)
expr_stmt|;
name|setCentralWidget
argument_list|(
name|tabWidget
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|setDirectory
name|void
name|MainWindow
operator|::
name|setDirectory
parameter_list|(
specifier|const
name|QString
modifier|&
name|path
parameter_list|)
block|{
name|QDir
name|dir
argument_list|(
name|path
argument_list|)
decl_stmt|;
name|QStringList
name|files
init|=
name|dir
operator|.
name|entryList
argument_list|(
name|QDir
operator|::
name|Files
operator||
name|QDir
operator|::
name|Readable
operator||
name|QDir
operator|::
name|NoDotAndDotDot
argument_list|)
decl_stmt|;
foreach|foreach
control|(
specifier|const
name|QString
modifier|&
name|file
decl|,
name|files
control|)
block|{
name|QImageReader
name|img
argument_list|(
name|path
operator|+
name|QLatin1Char
argument_list|(
literal|'/'
argument_list|)
operator|+
name|file
argument_list|)
decl_stmt|;
name|QImage
name|image
init|=
name|img
operator|.
name|read
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|image
operator|.
name|isNull
argument_list|()
condition|)
block|{
block|{
name|ImageItem
modifier|*
name|item
init|=
operator|new
name|ImageItem
argument_list|(
name|image
argument_list|)
decl_stmt|;
name|item
operator|->
name|setPos
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|item
operator|->
name|setFlags
argument_list|(
name|QGraphicsItem
operator|::
name|ItemIsMovable
argument_list|)
expr_stmt|;
name|standardGestures
operator|->
name|scene
operator|->
name|addItem
argument_list|(
name|item
argument_list|)
expr_stmt|;
block|}
block|{
name|ImageItem
modifier|*
name|item
init|=
operator|new
name|ImageItem
argument_list|(
name|image
argument_list|)
decl_stmt|;
name|item
operator|->
name|setPos
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|item
operator|->
name|setFlags
argument_list|(
name|QGraphicsItem
operator|::
name|ItemIsMovable
argument_list|)
expr_stmt|;
name|globalViewGestures
operator|->
name|scene
operator|->
name|addItem
argument_list|(
name|item
argument_list|)
expr_stmt|;
block|}
block|{
name|GestureImageItem
modifier|*
name|item
init|=
operator|new
name|GestureImageItem
argument_list|(
name|image
argument_list|)
decl_stmt|;
name|item
operator|->
name|setPos
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|item
operator|->
name|setFlags
argument_list|(
name|QGraphicsItem
operator|::
name|ItemIsMovable
argument_list|)
expr_stmt|;
name|graphicsItemGestures
operator|->
name|scene
operator|->
name|addItem
argument_list|(
name|item
argument_list|)
expr_stmt|;
block|}
block|}
block|}
block|{
name|QList
argument_list|<
name|QGraphicsItem
modifier|*
argument_list|>
name|items
init|=
name|standardGestures
operator|->
name|scene
operator|->
name|items
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|items
operator|.
name|isEmpty
argument_list|()
condition|)
name|standardGestures
operator|->
name|view
operator|->
name|ensureVisible
argument_list|(
name|items
operator|.
name|at
argument_list|(
literal|0
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|{
name|QList
argument_list|<
name|QGraphicsItem
modifier|*
argument_list|>
name|items
init|=
name|globalViewGestures
operator|->
name|scene
operator|->
name|items
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|items
operator|.
name|isEmpty
argument_list|()
condition|)
name|globalViewGestures
operator|->
name|view
operator|->
name|ensureVisible
argument_list|(
name|items
operator|.
name|at
argument_list|(
literal|0
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|{
name|QList
argument_list|<
name|QGraphicsItem
modifier|*
argument_list|>
name|items
init|=
name|graphicsItemGestures
operator|->
name|scene
operator|->
name|items
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|items
operator|.
name|isEmpty
argument_list|()
condition|)
name|graphicsItemGestures
operator|->
name|view
operator|->
name|ensureVisible
argument_list|(
name|items
operator|.
name|at
argument_list|(
literal|0
argument_list|)
argument_list|)
expr_stmt|;
block|}
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
name|MainWindow
name|window
decl_stmt|;
if|if
condition|(
name|QApplication
operator|::
name|arguments
argument_list|()
operator|.
name|size
argument_list|()
operator|>
literal|1
condition|)
name|window
operator|.
name|setDirectory
argument_list|(
name|QApplication
operator|::
name|arguments
argument_list|()
operator|.
name|at
argument_list|(
literal|1
argument_list|)
argument_list|)
expr_stmt|;
else|else
name|window
operator|.
name|setDirectory
argument_list|(
name|QFileDialog
operator|::
name|getExistingDirectory
argument_list|(
literal|0
argument_list|,
literal|"Select image folder"
argument_list|)
argument_list|)
expr_stmt|;
name|window
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
