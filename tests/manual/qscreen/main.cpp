begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"propertywatcher.h"
end_include
begin_include
include|#
directive|include
file|<QApplication>
end_include
begin_include
include|#
directive|include
file|<QScreen>
end_include
begin_include
include|#
directive|include
file|<QWindow>
end_include
begin_include
include|#
directive|include
file|<QDebug>
end_include
begin_include
include|#
directive|include
file|<QTextStream>
end_include
begin_include
include|#
directive|include
file|<QFormLayout>
end_include
begin_include
include|#
directive|include
file|<QMainWindow>
end_include
begin_include
include|#
directive|include
file|<QMenu>
end_include
begin_include
include|#
directive|include
file|<QMenuBar>
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
file|<QLineEdit>
end_include
begin_include
include|#
directive|include
file|<QDesktopWidget>
end_include
begin_include
include|#
directive|include
file|<QPushButton>
end_include
begin_include
include|#
directive|include
file|<QLabel>
end_include
begin_include
include|#
directive|include
file|<QMouseEvent>
end_include
begin_class
DECL|class|MouseMonitor
class|class
name|MouseMonitor
super|:
specifier|public
name|QLabel
block|{
name|Q_OBJECT
public|public:
DECL|function|MouseMonitor
name|MouseMonitor
parameter_list|()
member_init_list|:
name|m_grabbed
argument_list|(
literal|false
argument_list|)
block|{
name|setMinimumSize
argument_list|(
literal|540
argument_list|,
literal|240
argument_list|)
expr_stmt|;
name|setAlignment
argument_list|(
name|Qt
operator|::
name|AlignCenter
argument_list|)
expr_stmt|;
name|setMouseTracking
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|setWindowTitle
argument_list|(
name|QLatin1String
argument_list|(
literal|"Mouse Monitor"
argument_list|)
argument_list|)
expr_stmt|;
name|updateText
argument_list|()
expr_stmt|;
block|}
DECL|function|updateText
name|void
name|updateText
parameter_list|()
block|{
name|QString
name|txt
init|=
name|m_grabbed
condition|?
name|QLatin1String
argument_list|(
literal|"Left-click to test QGuiApplication::topLevelAt(click pos)\nRight-click to ungrab\n"
argument_list|)
else|:
name|QLatin1String
argument_list|(
literal|"Left-click to grab mouse\n"
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|m_cursorPos
operator|.
name|isNull
argument_list|()
condition|)
block|{
name|txt
operator|+=
name|QString
argument_list|(
name|QLatin1String
argument_list|(
literal|"Current mouse position: %1, %2 on screen %3\n"
argument_list|)
argument_list|)
operator|.
name|arg
argument_list|(
name|m_cursorPos
operator|.
name|x
argument_list|()
argument_list|)
operator|.
name|arg
argument_list|(
name|m_cursorPos
operator|.
name|y
argument_list|()
argument_list|)
operator|.
name|arg
argument_list|(
name|QApplication
operator|::
name|desktop
argument_list|()
operator|->
name|screenNumber
argument_list|(
name|m_cursorPos
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|QGuiApplication
operator|::
name|mouseButtons
argument_list|()
operator|&
name|Qt
operator|::
name|LeftButton
condition|)
block|{
name|QWindow
modifier|*
name|win
init|=
name|QGuiApplication
operator|::
name|topLevelAt
argument_list|(
name|m_cursorPos
argument_list|)
decl_stmt|;
name|txt
operator|+=
name|QString
argument_list|(
name|QLatin1String
argument_list|(
literal|"Top-level window found? %1\n"
argument_list|)
argument_list|)
operator|.
name|arg
argument_list|(
name|win
condition|?
operator|(
name|win
operator|->
name|title
argument_list|()
operator|.
name|isEmpty
argument_list|()
condition|?
literal|"no title"
else|:
name|win
operator|->
name|title
argument_list|()
operator|)
else|:
literal|"none"
argument_list|)
expr_stmt|;
block|}
block|}
name|setText
argument_list|(
name|txt
argument_list|)
expr_stmt|;
block|}
protected|protected:
name|void
name|mouseMoveEvent
parameter_list|(
name|QMouseEvent
modifier|*
name|ev
parameter_list|)
name|Q_DECL_OVERRIDE
block|{
name|m_cursorPos
operator|=
name|ev
operator|->
name|screenPos
argument_list|()
operator|.
name|toPoint
argument_list|()
expr_stmt|;
name|updateText
argument_list|()
expr_stmt|;
block|}
name|void
name|mousePressEvent
parameter_list|(
name|QMouseEvent
modifier|*
name|ev
parameter_list|)
name|Q_DECL_OVERRIDE
block|{
name|m_cursorPos
operator|=
name|ev
operator|->
name|screenPos
argument_list|()
operator|.
name|toPoint
argument_list|()
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"top level @"
operator|<<
name|m_cursorPos
operator|<<
literal|":"
operator|<<
name|QGuiApplication
operator|::
name|topLevelAt
argument_list|(
name|m_cursorPos
argument_list|)
expr_stmt|;
name|updateText
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|m_grabbed
condition|)
block|{
name|grabMouse
argument_list|(
name|Qt
operator|::
name|CrossCursor
argument_list|)
expr_stmt|;
name|m_grabbed
operator|=
literal|true
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|ev
operator|->
name|button
argument_list|()
operator|==
name|Qt
operator|::
name|RightButton
condition|)
block|{
name|setVisible
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|deleteLater
argument_list|()
expr_stmt|;
block|}
block|}
private|private:
DECL|member|m_cursorPos
name|QPoint
name|m_cursorPos
decl_stmt|;
DECL|member|m_grabbed
name|bool
name|m_grabbed
decl_stmt|;
block|}
class|;
end_class
begin_class
DECL|class|ScreenPropertyWatcher
class|class
name|ScreenPropertyWatcher
super|:
specifier|public
name|PropertyWatcher
block|{
name|Q_OBJECT
public|public:
DECL|function|ScreenPropertyWatcher
name|ScreenPropertyWatcher
parameter_list|(
name|QWidget
modifier|*
name|wp
init|=
name|Q_NULLPTR
parameter_list|)
member_init_list|:
name|PropertyWatcher
argument_list|(
name|Q_NULLPTR
argument_list|,
name|QString
argument_list|()
argument_list|,
name|wp
argument_list|)
block|{
comment|// workaround for the fact that virtualSiblings is not a property,
comment|// thus there is no change notification:
comment|// allow the user to update the field manually
name|connect
argument_list|(
name|this
argument_list|,
operator|&
name|PropertyWatcher
operator|::
name|updatedAllFields
argument_list|,
name|this
argument_list|,
operator|&
name|ScreenPropertyWatcher
operator|::
name|updateSiblings
argument_list|)
expr_stmt|;
block|}
DECL|function|screenSubject
name|QScreen
modifier|*
name|screenSubject
parameter_list|()
specifier|const
block|{
return|return
name|qobject_cast
argument_list|<
name|QScreen
operator|*
argument_list|>
argument_list|(
name|subject
argument_list|()
argument_list|)
return|;
block|}
DECL|function|setScreenSubject
name|void
name|setScreenSubject
parameter_list|(
name|QScreen
modifier|*
name|s
parameter_list|,
specifier|const
name|QString
modifier|&
name|annotation
init|=
name|QString
argument_list|()
parameter_list|)
block|{
name|setSubject
argument_list|(
name|s
argument_list|,
name|annotation
argument_list|)
expr_stmt|;
name|updateSiblings
argument_list|()
expr_stmt|;
block|}
public|public
name|slots
public|:
name|void
name|updateSiblings
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|updateSiblings
name|void
name|ScreenPropertyWatcher
operator|::
name|updateSiblings
parameter_list|()
block|{
specifier|const
name|QScreen
modifier|*
name|screen
init|=
name|screenSubject
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|screen
condition|)
return|return;
specifier|const
name|QString
name|objectName
init|=
name|QLatin1String
argument_list|(
literal|"siblings"
argument_list|)
decl_stmt|;
name|QLineEdit
modifier|*
name|siblingsField
init|=
name|findChild
argument_list|<
name|QLineEdit
operator|*
argument_list|>
argument_list|(
name|objectName
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|siblingsField
condition|)
block|{
name|siblingsField
operator|=
operator|new
name|QLineEdit
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|siblingsField
operator|->
name|setObjectName
argument_list|(
name|objectName
argument_list|)
expr_stmt|;
name|siblingsField
operator|->
name|setReadOnly
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|formLayout
argument_list|()
operator|->
name|insertRow
argument_list|(
literal|0
argument_list|,
name|QLatin1String
argument_list|(
literal|"virtualSiblings"
argument_list|)
argument_list|,
name|siblingsField
argument_list|)
expr_stmt|;
block|}
name|QString
name|text
decl_stmt|;
foreach|foreach
control|(
specifier|const
name|QScreen
modifier|*
name|sibling
decl|,
name|screen
operator|->
name|virtualSiblings
argument_list|()
control|)
block|{
if|if
condition|(
operator|!
name|text
operator|.
name|isEmpty
argument_list|()
condition|)
name|text
operator|+=
name|QLatin1String
argument_list|(
literal|", "
argument_list|)
expr_stmt|;
name|text
operator|+=
name|sibling
operator|->
name|name
argument_list|()
expr_stmt|;
block|}
name|siblingsField
operator|->
name|setText
argument_list|(
name|text
argument_list|)
expr_stmt|;
block|}
end_function
begin_class
DECL|class|ScreenWatcherMainWindow
class|class
name|ScreenWatcherMainWindow
super|:
specifier|public
name|QMainWindow
block|{
name|Q_OBJECT
public|public:
specifier|explicit
name|ScreenWatcherMainWindow
parameter_list|(
name|QScreen
modifier|*
name|screen
parameter_list|)
constructor_decl|;
DECL|function|screenSubject
name|QScreen
modifier|*
name|screenSubject
parameter_list|()
specifier|const
block|{
return|return
name|m_watcher
operator|->
name|screenSubject
argument_list|()
return|;
block|}
protected|protected:
DECL|member|Q_DECL_OVERRIDE
name|bool
name|event
parameter_list|(
name|QEvent
modifier|*
name|event
parameter_list|)
name|Q_DECL_OVERRIDE
function_decl|;
name|void
name|startMouseMonitor
parameter_list|()
function_decl|;
private|private:
DECL|member|m_annotation
specifier|const
name|QString
name|m_annotation
decl_stmt|;
DECL|member|m_watcher
name|ScreenPropertyWatcher
modifier|*
name|m_watcher
decl_stmt|;
block|}
class|;
end_class
begin_decl_stmt
DECL|variable|i
specifier|static
name|int
name|i
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_constructor
DECL|function|ScreenWatcherMainWindow
name|ScreenWatcherMainWindow
operator|::
name|ScreenWatcherMainWindow
parameter_list|(
name|QScreen
modifier|*
name|screen
parameter_list|)
member_init_list|:
name|m_annotation
argument_list|(
name|QLatin1Char
argument_list|(
literal|'#'
argument_list|)
operator|+
name|QString
operator|::
name|number
argument_list|(
name|i
operator|++
argument_list|)
argument_list|)
member_init_list|,
name|m_watcher
argument_list|(
operator|new
name|ScreenPropertyWatcher
argument_list|(
name|this
argument_list|)
argument_list|)
block|{
name|setAttribute
argument_list|(
name|Qt
operator|::
name|WA_DeleteOnClose
argument_list|)
expr_stmt|;
name|setCentralWidget
argument_list|(
name|m_watcher
argument_list|)
expr_stmt|;
name|m_watcher
operator|->
name|setScreenSubject
argument_list|(
name|screen
argument_list|,
name|m_annotation
argument_list|)
expr_stmt|;
name|QMenu
modifier|*
name|fileMenu
init|=
name|menuBar
argument_list|()
operator|->
name|addMenu
argument_list|(
name|QLatin1String
argument_list|(
literal|"&File"
argument_list|)
argument_list|)
decl_stmt|;
name|QAction
modifier|*
name|a
init|=
name|fileMenu
operator|->
name|addAction
argument_list|(
name|QLatin1String
argument_list|(
literal|"Close"
argument_list|)
argument_list|)
decl_stmt|;
name|a
operator|->
name|setShortcut
argument_list|(
name|QKeySequence
argument_list|(
name|Qt
operator|::
name|CTRL
operator|+
name|Qt
operator|::
name|Key_W
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|a
argument_list|,
name|SIGNAL
argument_list|(
name|triggered
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|close
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|a
operator|=
name|fileMenu
operator|->
name|addAction
argument_list|(
name|QLatin1String
argument_list|(
literal|"Quit"
argument_list|)
argument_list|)
expr_stmt|;
name|a
operator|->
name|setShortcut
argument_list|(
name|QKeySequence
argument_list|(
name|Qt
operator|::
name|CTRL
operator|+
name|Qt
operator|::
name|Key_Q
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|a
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
name|QMenu
modifier|*
name|toolsMenu
init|=
name|menuBar
argument_list|()
operator|->
name|addMenu
argument_list|(
name|QLatin1String
argument_list|(
literal|"&Tools"
argument_list|)
argument_list|)
decl_stmt|;
name|a
operator|=
name|toolsMenu
operator|->
name|addAction
argument_list|(
name|QLatin1String
argument_list|(
literal|"Mouse Monitor"
argument_list|)
argument_list|)
expr_stmt|;
name|a
operator|->
name|setShortcut
argument_list|(
name|QKeySequence
argument_list|(
name|Qt
operator|::
name|CTRL
operator|+
name|Qt
operator|::
name|Key_M
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|a
argument_list|,
operator|&
name|QAction
operator|::
name|triggered
argument_list|,
name|this
argument_list|,
operator|&
name|ScreenWatcherMainWindow
operator|::
name|startMouseMonitor
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|msgScreenChange
specifier|static
specifier|inline
name|QString
name|msgScreenChange
parameter_list|(
specifier|const
name|QWidget
modifier|*
name|w
parameter_list|,
specifier|const
name|QScreen
modifier|*
name|oldScreen
parameter_list|,
specifier|const
name|QScreen
modifier|*
name|newScreen
parameter_list|)
block|{
name|QString
name|result
decl_stmt|;
specifier|const
name|QRect
name|geometry
init|=
name|w
operator|->
name|geometry
argument_list|()
decl_stmt|;
specifier|const
name|QPoint
name|pos
init|=
name|QCursor
operator|::
name|pos
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|newScreen
condition|)
block|{
name|result
operator|=
name|QLatin1String
argument_list|(
literal|"Screen changed --> null"
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
operator|!
name|oldScreen
condition|)
block|{
name|QTextStream
argument_list|(
operator|&
name|result
argument_list|)
operator|<<
literal|"Screen changed null --> \""
operator|<<
name|newScreen
operator|->
name|name
argument_list|()
operator|<<
literal|"\" at "
operator|<<
name|pos
operator|.
name|x
argument_list|()
operator|<<
literal|','
operator|<<
name|pos
operator|.
name|y
argument_list|()
operator|<<
literal|" geometry: "
operator|<<
name|geometry
operator|.
name|width
argument_list|()
operator|<<
literal|'x'
operator|<<
name|geometry
operator|.
name|height
argument_list|()
operator|<<
name|forcesign
operator|<<
name|geometry
operator|.
name|x
argument_list|()
operator|<<
name|geometry
operator|.
name|y
argument_list|()
operator|<<
literal|'.'
expr_stmt|;
block|}
else|else
block|{
name|QTextStream
argument_list|(
operator|&
name|result
argument_list|)
operator|<<
literal|"Screen changed \""
operator|<<
name|oldScreen
operator|->
name|name
argument_list|()
operator|<<
literal|"\" --> \""
operator|<<
name|newScreen
operator|->
name|name
argument_list|()
operator|<<
literal|"\" at "
operator|<<
name|pos
operator|.
name|x
argument_list|()
operator|<<
literal|','
operator|<<
name|pos
operator|.
name|y
argument_list|()
operator|<<
literal|" geometry: "
operator|<<
name|geometry
operator|.
name|width
argument_list|()
operator|<<
literal|'x'
operator|<<
name|geometry
operator|.
name|height
argument_list|()
operator|<<
name|forcesign
operator|<<
name|geometry
operator|.
name|x
argument_list|()
operator|<<
name|geometry
operator|.
name|y
argument_list|()
operator|<<
literal|'.'
expr_stmt|;
block|}
return|return
name|result
return|;
block|}
end_function
begin_function
DECL|function|event
name|bool
name|ScreenWatcherMainWindow
operator|::
name|event
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
name|ScreenChangeInternal
condition|)
block|{
name|QScreen
modifier|*
name|newScreen
init|=
name|windowHandle
argument_list|()
operator|->
name|screen
argument_list|()
decl_stmt|;
specifier|const
name|QString
name|message
init|=
name|msgScreenChange
argument_list|(
name|this
argument_list|,
name|m_watcher
operator|->
name|screenSubject
argument_list|()
argument_list|,
name|newScreen
argument_list|)
decl_stmt|;
name|qDebug
argument_list|()
operator|.
name|noquote
argument_list|()
operator|<<
name|message
expr_stmt|;
name|statusBar
argument_list|()
operator|->
name|showMessage
argument_list|(
name|message
argument_list|)
expr_stmt|;
name|m_watcher
operator|->
name|setScreenSubject
argument_list|(
name|newScreen
argument_list|,
name|m_annotation
argument_list|)
expr_stmt|;
block|}
return|return
name|QMainWindow
operator|::
name|event
argument_list|(
name|event
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|startMouseMonitor
name|void
name|ScreenWatcherMainWindow
operator|::
name|startMouseMonitor
parameter_list|()
block|{
name|MouseMonitor
modifier|*
name|mm
init|=
operator|new
name|MouseMonitor
argument_list|()
decl_stmt|;
name|mm
operator|->
name|show
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|screenAdded
name|void
name|screenAdded
parameter_list|(
name|QScreen
modifier|*
name|screen
parameter_list|)
block|{
name|screen
operator|->
name|setOrientationUpdateMask
argument_list|(
operator|(
name|Qt
operator|::
name|ScreenOrientations
operator|)
literal|0x0F
argument_list|)
expr_stmt|;
name|qDebug
argument_list|(
literal|"\nscreenAdded %s siblings %d first %s"
argument_list|,
name|qPrintable
argument_list|(
name|screen
operator|->
name|name
argument_list|()
argument_list|)
argument_list|,
name|screen
operator|->
name|virtualSiblings
argument_list|()
operator|.
name|count
argument_list|()
argument_list|,
operator|(
name|screen
operator|->
name|virtualSiblings
argument_list|()
operator|.
name|isEmpty
argument_list|()
condition|?
literal|"none"
else|:
name|qPrintable
argument_list|(
name|screen
operator|->
name|virtualSiblings
argument_list|()
operator|.
name|first
argument_list|()
operator|->
name|name
argument_list|()
argument_list|)
operator|)
argument_list|)
expr_stmt|;
name|ScreenWatcherMainWindow
modifier|*
name|w
init|=
operator|new
name|ScreenWatcherMainWindow
argument_list|(
name|screen
argument_list|)
decl_stmt|;
comment|// Set the screen via QDesktopWidget. This corresponds to setScreen() for the underlying
comment|// QWindow. This is essential when having separate X screens since the the positioning below is
comment|// not sufficient to get the windows show up on the desired screen.
name|QList
argument_list|<
name|QScreen
modifier|*
argument_list|>
name|screens
init|=
name|QGuiApplication
operator|::
name|screens
argument_list|()
decl_stmt|;
name|int
name|screenNumber
init|=
name|screens
operator|.
name|indexOf
argument_list|(
name|screen
argument_list|)
decl_stmt|;
name|Q_ASSERT
argument_list|(
name|screenNumber
operator|>=
literal|0
argument_list|)
expr_stmt|;
name|w
operator|->
name|setParent
argument_list|(
name|qApp
operator|->
name|desktop
argument_list|()
operator|->
name|screen
argument_list|(
name|screenNumber
argument_list|)
argument_list|)
expr_stmt|;
name|w
operator|->
name|show
argument_list|()
expr_stmt|;
comment|// Position the windows so that they end up at the center of the corresponding screen.
name|QRect
name|geom
init|=
name|w
operator|->
name|geometry
argument_list|()
decl_stmt|;
name|geom
operator|.
name|setSize
argument_list|(
name|w
operator|->
name|sizeHint
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|geom
operator|.
name|height
argument_list|()
operator|>
name|screen
operator|->
name|geometry
argument_list|()
operator|.
name|height
argument_list|()
condition|)
name|geom
operator|.
name|setHeight
argument_list|(
name|screen
operator|->
name|geometry
argument_list|()
operator|.
name|height
argument_list|()
operator|*
literal|9
operator|/
literal|10
argument_list|)
expr_stmt|;
name|geom
operator|.
name|moveCenter
argument_list|(
name|screen
operator|->
name|geometry
argument_list|()
operator|.
name|center
argument_list|()
argument_list|)
expr_stmt|;
name|w
operator|->
name|setGeometry
argument_list|(
name|geom
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|screenRemoved
name|void
name|screenRemoved
parameter_list|(
name|QScreen
modifier|*
name|screen
parameter_list|)
block|{
specifier|const
name|QWidgetList
name|topLevels
init|=
name|QApplication
operator|::
name|topLevelWidgets
argument_list|()
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
name|topLevels
operator|.
name|size
argument_list|()
operator|-
literal|1
init|;
name|i
operator|>=
literal|0
condition|;
operator|--
name|i
control|)
block|{
if|if
condition|(
name|ScreenWatcherMainWindow
modifier|*
name|sw
init|=
name|qobject_cast
argument_list|<
name|ScreenWatcherMainWindow
operator|*
argument_list|>
argument_list|(
name|topLevels
operator|.
name|at
argument_list|(
name|i
argument_list|)
argument_list|)
condition|)
block|{
if|if
condition|(
name|sw
operator|->
name|screenSubject
argument_list|()
operator|==
name|screen
condition|)
name|sw
operator|->
name|close
argument_list|()
expr_stmt|;
block|}
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
name|argv
index|[]
parameter_list|)
block|{
name|QApplication
name|a
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
decl_stmt|;
name|QList
argument_list|<
name|QScreen
modifier|*
argument_list|>
name|screens
init|=
name|QGuiApplication
operator|::
name|screens
argument_list|()
decl_stmt|;
foreach|foreach
control|(
name|QScreen
modifier|*
name|screen
decl|,
name|screens
control|)
name|screenAdded
argument_list|(
name|screen
argument_list|)
expr_stmt|;
name|QObject
operator|::
name|connect
argument_list|(
operator|(
specifier|const
name|QGuiApplication
operator|*
operator|)
name|QGuiApplication
operator|::
name|instance
argument_list|()
argument_list|,
operator|&
name|QGuiApplication
operator|::
name|screenAdded
argument_list|,
operator|&
name|screenAdded
argument_list|)
expr_stmt|;
name|QObject
operator|::
name|connect
argument_list|(
operator|(
specifier|const
name|QGuiApplication
operator|*
operator|)
name|QGuiApplication
operator|::
name|instance
argument_list|()
argument_list|,
operator|&
name|QGuiApplication
operator|::
name|screenRemoved
argument_list|,
operator|&
name|screenRemoved
argument_list|)
expr_stmt|;
return|return
name|a
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
