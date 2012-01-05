begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtGui>
end_include
begin_class
DECL|class|DesktopView
class|class
name|DesktopView
super|:
specifier|public
name|QGraphicsView
block|{
name|Q_OBJECT
public|public:
DECL|function|DesktopView
name|DesktopView
parameter_list|()
member_init_list|:
name|that
argument_list|(
literal|0
argument_list|)
block|{
name|scene
operator|=
operator|new
name|QGraphicsScene
expr_stmt|;
name|setScene
argument_list|(
name|scene
argument_list|)
expr_stmt|;
name|QDesktopWidget
modifier|*
name|desktop
init|=
name|QApplication
operator|::
name|desktop
argument_list|()
decl_stmt|;
name|connect
argument_list|(
name|desktop
argument_list|,
name|SIGNAL
argument_list|(
name|resized
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|updateScene
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|desktop
argument_list|,
name|SIGNAL
argument_list|(
name|resized
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|desktopResized
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|desktop
argument_list|,
name|SIGNAL
argument_list|(
name|workAreaResized
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|updateScene
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|desktop
argument_list|,
name|SIGNAL
argument_list|(
name|workAreaResized
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|desktopWorkAreaResized
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|desktop
argument_list|,
name|SIGNAL
argument_list|(
name|screenCountChanged
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|updateScene
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|desktop
argument_list|,
name|SIGNAL
argument_list|(
name|screenCountChanged
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|desktopScreenCountChanged
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|updateScene
argument_list|()
expr_stmt|;
name|QTransform
name|transform
decl_stmt|;
name|transform
operator|.
name|scale
argument_list|(
literal|0.25
argument_list|,
literal|0.25
argument_list|)
expr_stmt|;
name|setTransform
argument_list|(
name|transform
argument_list|)
expr_stmt|;
name|setBackgroundBrush
argument_list|(
name|Qt
operator|::
name|darkGray
argument_list|)
expr_stmt|;
name|desktopScreenCountChanged
argument_list|(
operator|-
literal|1
argument_list|)
expr_stmt|;
block|}
protected|protected:
DECL|function|moveEvent
name|void
name|moveEvent
parameter_list|(
name|QMoveEvent
modifier|*
name|e
parameter_list|)
block|{
if|if
condition|(
name|that
condition|)
block|{
name|that
operator|->
name|setRect
argument_list|(
name|appRect
argument_list|()
argument_list|)
expr_stmt|;
name|scene
operator|->
name|update
argument_list|()
expr_stmt|;
block|}
name|QGraphicsView
operator|::
name|moveEvent
argument_list|(
name|e
argument_list|)
expr_stmt|;
block|}
DECL|function|resizeEvent
name|void
name|resizeEvent
parameter_list|(
name|QResizeEvent
modifier|*
name|e
parameter_list|)
block|{
if|if
condition|(
name|that
condition|)
block|{
name|that
operator|->
name|setRect
argument_list|(
name|appRect
argument_list|()
argument_list|)
expr_stmt|;
block|}
name|QGraphicsView
operator|::
name|resizeEvent
argument_list|(
name|e
argument_list|)
expr_stmt|;
block|}
private|private
name|slots
private|:
DECL|function|updateScene
name|void
name|updateScene
parameter_list|()
block|{
name|scene
operator|->
name|clear
argument_list|()
expr_stmt|;
specifier|const
name|QDesktopWidget
modifier|*
name|desktop
init|=
name|QApplication
operator|::
name|desktop
argument_list|()
decl_stmt|;
specifier|const
name|bool
name|isVirtualDesktop
init|=
name|desktop
operator|->
name|isVirtualDesktop
argument_list|()
decl_stmt|;
specifier|const
name|int
name|homeScreen
init|=
name|desktop
operator|->
name|screenNumber
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|QRect
name|sceneRect
decl_stmt|;
name|int
name|screenCount
init|=
name|desktop
operator|->
name|screenCount
argument_list|()
decl_stmt|;
for|for
control|(
name|int
name|s
init|=
literal|0
init|;
name|s
operator|<
name|screenCount
condition|;
operator|++
name|s
control|)
block|{
specifier|const
name|bool
name|isPrimary
init|=
name|desktop
operator|->
name|primaryScreen
argument_list|()
operator|==
name|s
decl_stmt|;
specifier|const
name|QRect
name|screenRect
init|=
name|desktop
operator|->
name|screenGeometry
argument_list|(
name|s
argument_list|)
decl_stmt|;
specifier|const
name|QRect
name|workRect
init|=
name|desktop
operator|->
name|availableGeometry
argument_list|(
name|s
argument_list|)
decl_stmt|;
specifier|const
name|QBrush
name|fillBrush
init|=
name|palette
argument_list|()
operator|.
name|brush
argument_list|(
name|isPrimary
condition|?
name|QPalette
operator|::
name|Active
else|:
name|QPalette
operator|::
name|Inactive
argument_list|,
name|QPalette
operator|::
name|Highlight
argument_list|)
decl_stmt|;
name|QGraphicsRectItem
modifier|*
name|screen
init|=
operator|new
name|QGraphicsRectItem
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|screenRect
operator|.
name|width
argument_list|()
argument_list|,
name|screenRect
operator|.
name|height
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|isVirtualDesktop
condition|)
block|{
name|thatRoot
operator|=
name|QPoint
argument_list|()
expr_stmt|;
name|screen
operator|->
name|setPos
argument_list|(
name|screenRect
operator|.
name|x
argument_list|()
argument_list|,
name|screenRect
operator|.
name|y
argument_list|()
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|// for non-virtual desktops we assume that screens are
comment|// simply next to each other
if|if
condition|(
name|s
condition|)
name|screen
operator|->
name|setPos
argument_list|(
name|sceneRect
operator|.
name|right
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|s
operator|==
name|homeScreen
condition|)
name|thatRoot
operator|=
name|screen
operator|->
name|pos
argument_list|()
operator|.
name|toPoint
argument_list|()
expr_stmt|;
block|}
name|screen
operator|->
name|setBrush
argument_list|(
name|fillBrush
argument_list|)
expr_stmt|;
name|scene
operator|->
name|addItem
argument_list|(
name|screen
argument_list|)
expr_stmt|;
name|sceneRect
operator|.
name|setLeft
argument_list|(
name|qMin
argument_list|(
name|sceneRect
operator|.
name|left
argument_list|()
argument_list|,
name|screenRect
operator|.
name|left
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|sceneRect
operator|.
name|setRight
argument_list|(
name|qMax
argument_list|(
name|sceneRect
operator|.
name|right
argument_list|()
argument_list|,
name|screenRect
operator|.
name|right
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|sceneRect
operator|.
name|setTop
argument_list|(
name|qMin
argument_list|(
name|sceneRect
operator|.
name|top
argument_list|()
argument_list|,
name|screenRect
operator|.
name|top
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|sceneRect
operator|.
name|setBottom
argument_list|(
name|qMax
argument_list|(
name|sceneRect
operator|.
name|bottom
argument_list|()
argument_list|,
name|screenRect
operator|.
name|bottom
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|QGraphicsRectItem
modifier|*
name|workArea
init|=
operator|new
name|QGraphicsRectItem
argument_list|(
name|screen
argument_list|)
decl_stmt|;
name|workArea
operator|->
name|setRect
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|workRect
operator|.
name|width
argument_list|()
argument_list|,
name|workRect
operator|.
name|height
argument_list|()
argument_list|)
expr_stmt|;
name|workArea
operator|->
name|setPos
argument_list|(
name|workRect
operator|.
name|x
argument_list|()
operator|-
name|screenRect
operator|.
name|x
argument_list|()
argument_list|,
name|workRect
operator|.
name|y
argument_list|()
operator|-
name|screenRect
operator|.
name|y
argument_list|()
argument_list|)
expr_stmt|;
name|workArea
operator|->
name|setBrush
argument_list|(
name|Qt
operator|::
name|white
argument_list|)
expr_stmt|;
name|QGraphicsSimpleTextItem
modifier|*
name|screenNumber
init|=
operator|new
name|QGraphicsSimpleTextItem
argument_list|(
name|workArea
argument_list|)
decl_stmt|;
name|screenNumber
operator|->
name|setText
argument_list|(
name|QString
operator|::
name|number
argument_list|(
name|s
argument_list|)
argument_list|)
expr_stmt|;
name|screenNumber
operator|->
name|setPen
argument_list|(
name|QPen
argument_list|(
name|Qt
operator|::
name|black
argument_list|,
literal|1
argument_list|)
argument_list|)
expr_stmt|;
name|screenNumber
operator|->
name|setBrush
argument_list|(
name|fillBrush
argument_list|)
expr_stmt|;
name|screenNumber
operator|->
name|setFont
argument_list|(
name|QFont
argument_list|(
literal|"Arial Black"
argument_list|,
literal|18
argument_list|)
argument_list|)
expr_stmt|;
name|screenNumber
operator|->
name|setTransform
argument_list|(
name|QTransform
argument_list|()
operator|.
name|scale
argument_list|(
literal|10
argument_list|,
literal|10
argument_list|)
argument_list|)
expr_stmt|;
name|screenNumber
operator|->
name|setTransformOriginPoint
argument_list|(
name|screenNumber
operator|->
name|boundingRect
argument_list|()
operator|.
name|center
argument_list|()
argument_list|)
expr_stmt|;
name|QSizeF
name|center
init|=
operator|(
name|workRect
operator|.
name|size
argument_list|()
operator|-
name|screenNumber
operator|->
name|boundingRect
argument_list|()
operator|.
name|size
argument_list|()
operator|)
operator|/
literal|2
decl_stmt|;
name|screenNumber
operator|->
name|setPos
argument_list|(
name|center
operator|.
name|width
argument_list|()
argument_list|,
name|center
operator|.
name|height
argument_list|()
argument_list|)
expr_stmt|;
name|screen
operator|->
name|show
argument_list|()
expr_stmt|;
name|screen
operator|->
name|setZValue
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|isVirtualDesktop
condition|)
block|{
name|QGraphicsRectItem
modifier|*
name|virtualDesktop
init|=
operator|new
name|QGraphicsRectItem
decl_stmt|;
name|virtualDesktop
operator|->
name|setRect
argument_list|(
name|sceneRect
argument_list|)
expr_stmt|;
name|virtualDesktop
operator|->
name|setPen
argument_list|(
name|QPen
argument_list|(
name|Qt
operator|::
name|black
argument_list|)
argument_list|)
expr_stmt|;
name|virtualDesktop
operator|->
name|setBrush
argument_list|(
name|Qt
operator|::
name|DiagCrossPattern
argument_list|)
expr_stmt|;
name|scene
operator|->
name|addItem
argument_list|(
name|virtualDesktop
argument_list|)
expr_stmt|;
name|virtualDesktop
operator|->
name|setZValue
argument_list|(
operator|-
literal|1
argument_list|)
expr_stmt|;
name|virtualDesktop
operator|->
name|show
argument_list|()
expr_stmt|;
block|}
name|that
operator|=
operator|new
name|QGraphicsRectItem
expr_stmt|;
name|that
operator|->
name|setBrush
argument_list|(
name|Qt
operator|::
name|red
argument_list|)
expr_stmt|;
name|that
operator|->
name|setOpacity
argument_list|(
literal|0.5
argument_list|)
expr_stmt|;
name|that
operator|->
name|setZValue
argument_list|(
literal|2
argument_list|)
expr_stmt|;
name|that
operator|->
name|setRect
argument_list|(
name|appRect
argument_list|()
argument_list|)
expr_stmt|;
name|that
operator|->
name|show
argument_list|()
expr_stmt|;
name|scene
operator|->
name|addItem
argument_list|(
name|that
argument_list|)
expr_stmt|;
name|scene
operator|->
name|setSceneRect
argument_list|(
name|sceneRect
argument_list|)
expr_stmt|;
name|scene
operator|->
name|update
argument_list|()
expr_stmt|;
block|}
DECL|function|appRect
name|QRect
name|appRect
parameter_list|()
specifier|const
block|{
name|QRect
name|rect
init|=
name|frameGeometry
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|QApplication
operator|::
name|desktop
argument_list|()
operator|->
name|isVirtualDesktop
argument_list|()
condition|)
block|{
name|rect
operator|.
name|translate
argument_list|(
name|thatRoot
argument_list|)
expr_stmt|;
block|}
return|return
name|rect
return|;
block|}
DECL|function|desktopResized
name|void
name|desktopResized
parameter_list|(
name|int
name|screen
parameter_list|)
block|{
name|qDebug
argument_list|()
operator|<<
literal|"Screen was resized: "
operator|<<
name|screen
operator|<<
literal|", new size ="
operator|<<
name|QApplication
operator|::
name|desktop
argument_list|()
operator|->
name|screenGeometry
argument_list|(
name|screen
argument_list|)
expr_stmt|;
block|}
DECL|function|desktopWorkAreaResized
name|void
name|desktopWorkAreaResized
parameter_list|(
name|int
name|screen
parameter_list|)
block|{
name|qDebug
argument_list|()
operator|<<
literal|"Screen workarea was resized: "
operator|<<
name|screen
operator|<<
literal|", new size ="
operator|<<
name|QApplication
operator|::
name|desktop
argument_list|()
operator|->
name|availableGeometry
argument_list|(
name|screen
argument_list|)
expr_stmt|;
block|}
DECL|function|desktopScreenCountChanged
name|void
name|desktopScreenCountChanged
parameter_list|(
name|int
name|screenCount
parameter_list|)
block|{
name|QDesktopWidget
modifier|*
name|desktop
init|=
name|QApplication
operator|::
name|desktop
argument_list|()
decl_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|""
expr_stmt|;
if|if
condition|(
name|screenCount
operator|!=
operator|-
literal|1
condition|)
block|{
name|qDebug
argument_list|()
operator|<<
literal|"Screen count was changed to "
operator|<<
name|screenCount
expr_stmt|;
block|}
else|else
block|{
name|screenCount
operator|=
name|desktop
operator|->
name|screenCount
argument_list|()
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"Screen count: "
operator|<<
name|screenCount
expr_stmt|;
block|}
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|screenCount
condition|;
operator|++
name|i
control|)
block|{
name|qDebug
argument_list|()
operator|<<
literal|"  #"
operator|<<
name|i
operator|<<
literal|": geometry ="
operator|<<
name|desktop
operator|->
name|screenGeometry
argument_list|(
name|i
argument_list|)
operator|<<
literal|"; available geometry ="
operator|<<
name|desktop
operator|->
name|availableGeometry
argument_list|(
name|i
argument_list|)
expr_stmt|;
block|}
name|qDebug
argument_list|()
operator|<<
literal|""
expr_stmt|;
block|}
private|private:
DECL|member|scene
name|QGraphicsScene
modifier|*
name|scene
decl_stmt|;
DECL|member|that
name|QGraphicsRectItem
modifier|*
name|that
decl_stmt|;
DECL|member|thatRoot
name|QPoint
name|thatRoot
decl_stmt|;
block|}
class|;
end_class
begin_include
include|#
directive|include
file|"main.moc"
end_include
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
name|DesktopView
name|view
decl_stmt|;
name|view
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
end_unit
