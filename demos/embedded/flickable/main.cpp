begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the demonstration applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtCore>
end_include
begin_include
include|#
directive|include
file|<QtWidgets>
end_include
begin_include
include|#
directive|include
file|"flickable.h"
end_include
begin_comment
comment|// Returns a list of two-word color names
end_comment
begin_function
DECL|function|colorPairs
specifier|static
name|QStringList
name|colorPairs
parameter_list|(
name|int
name|max
parameter_list|)
block|{
comment|// capitalize the first letter
name|QStringList
name|colors
init|=
name|QColor
operator|::
name|colorNames
argument_list|()
decl_stmt|;
name|colors
operator|.
name|removeAll
argument_list|(
literal|"transparent"
argument_list|)
expr_stmt|;
name|int
name|num
init|=
name|colors
operator|.
name|count
argument_list|()
decl_stmt|;
for|for
control|(
name|int
name|c
init|=
literal|0
init|;
name|c
operator|<
name|num
condition|;
operator|++
name|c
control|)
name|colors
index|[
name|c
index|]
operator|=
name|colors
index|[
name|c
index|]
index|[
literal|0
index|]
operator|.
name|toUpper
argument_list|()
operator|+
name|colors
index|[
name|c
index|]
operator|.
name|mid
argument_list|(
literal|1
argument_list|)
expr_stmt|;
comment|// combine two colors, e.g. "lime skyblue"
name|QStringList
name|combinedColors
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
name|num
condition|;
operator|++
name|i
control|)
for|for
control|(
name|int
name|j
init|=
literal|0
init|;
name|j
operator|<
name|num
condition|;
operator|++
name|j
control|)
name|combinedColors
operator|<<
name|QString
argument_list|(
literal|"%1 %2"
argument_list|)
operator|.
name|arg
argument_list|(
name|colors
index|[
name|i
index|]
argument_list|)
operator|.
name|arg
argument_list|(
name|colors
index|[
name|j
index|]
argument_list|)
expr_stmt|;
comment|// randomize it
name|colors
operator|.
name|clear
argument_list|()
expr_stmt|;
while|while
condition|(
name|combinedColors
operator|.
name|count
argument_list|()
condition|)
block|{
name|int
name|i
init|=
name|qrand
argument_list|()
operator|%
name|combinedColors
operator|.
name|count
argument_list|()
decl_stmt|;
name|colors
operator|<<
name|combinedColors
index|[
name|i
index|]
expr_stmt|;
name|combinedColors
operator|.
name|removeAt
argument_list|(
name|i
argument_list|)
expr_stmt|;
if|if
condition|(
name|colors
operator|.
name|count
argument_list|()
operator|==
name|max
condition|)
break|break;
block|}
return|return
name|colors
return|;
block|}
end_function
begin_class
DECL|class|ColorList
class|class
name|ColorList
super|:
specifier|public
name|QWidget
super|,
specifier|public
name|Flickable
block|{
name|Q_OBJECT
public|public:
DECL|function|ColorList
name|ColorList
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
name|m_offset
operator|=
literal|0
expr_stmt|;
name|m_height
operator|=
name|QFontMetrics
argument_list|(
name|font
argument_list|()
argument_list|)
operator|.
name|height
argument_list|()
operator|+
literal|5
expr_stmt|;
name|m_highlight
operator|=
operator|-
literal|1
expr_stmt|;
name|m_selected
operator|=
operator|-
literal|1
expr_stmt|;
name|QStringList
name|colors
init|=
name|colorPairs
argument_list|(
literal|999
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
name|colors
operator|.
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|QString
name|c
init|=
name|colors
index|[
name|i
index|]
decl_stmt|;
name|QString
name|str
decl_stmt|;
name|str
operator|.
name|sprintf
argument_list|(
literal|"%4d"
argument_list|,
name|i
operator|+
literal|1
argument_list|)
expr_stmt|;
name|m_colorNames
operator|<<
operator|(
name|str
operator|+
literal|"   "
operator|+
name|c
operator|)
expr_stmt|;
name|QStringList
name|duet
init|=
name|c
operator|.
name|split
argument_list|(
literal|' '
argument_list|)
decl_stmt|;
name|m_firstColor
operator|<<
name|duet
index|[
literal|0
index|]
expr_stmt|;
name|m_secondColor
operator|<<
name|duet
index|[
literal|1
index|]
expr_stmt|;
block|}
name|setAttribute
argument_list|(
name|Qt
operator|::
name|WA_OpaquePaintEvent
argument_list|,
literal|true
argument_list|)
expr_stmt|;
name|setAttribute
argument_list|(
name|Qt
operator|::
name|WA_NoSystemBackground
argument_list|,
literal|true
argument_list|)
expr_stmt|;
name|setMouseTracking
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|Flickable
operator|::
name|setAcceptMouseClick
argument_list|(
name|this
argument_list|)
expr_stmt|;
block|}
protected|protected:
comment|// reimplement from Flickable
DECL|function|scrollOffset
specifier|virtual
name|QPoint
name|scrollOffset
parameter_list|()
specifier|const
block|{
return|return
name|QPoint
argument_list|(
literal|0
argument_list|,
name|m_offset
argument_list|)
return|;
block|}
comment|// reimplement from Flickable
DECL|function|setScrollOffset
specifier|virtual
name|void
name|setScrollOffset
parameter_list|(
specifier|const
name|QPoint
modifier|&
name|offset
parameter_list|)
block|{
name|int
name|yy
init|=
name|offset
operator|.
name|y
argument_list|()
decl_stmt|;
if|if
condition|(
name|yy
operator|!=
name|m_offset
condition|)
block|{
name|m_offset
operator|=
name|qBound
argument_list|(
literal|0
argument_list|,
name|yy
argument_list|,
name|m_height
operator|*
name|m_colorNames
operator|.
name|count
argument_list|()
operator|-
name|height
argument_list|()
argument_list|)
expr_stmt|;
name|update
argument_list|()
expr_stmt|;
block|}
block|}
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
name|QPainter
name|p
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|p
operator|.
name|fillRect
argument_list|(
name|event
operator|->
name|rect
argument_list|()
argument_list|,
name|Qt
operator|::
name|white
argument_list|)
expr_stmt|;
name|int
name|start
init|=
name|m_offset
operator|/
name|m_height
decl_stmt|;
name|int
name|y
init|=
name|start
operator|*
name|m_height
operator|-
name|m_offset
decl_stmt|;
if|if
condition|(
name|m_offset
operator|<=
literal|0
condition|)
block|{
name|start
operator|=
literal|0
expr_stmt|;
name|y
operator|=
operator|-
name|m_offset
expr_stmt|;
block|}
name|int
name|end
init|=
name|start
operator|+
name|height
argument_list|()
operator|/
name|m_height
operator|+
literal|1
decl_stmt|;
if|if
condition|(
name|end
operator|>
name|m_colorNames
operator|.
name|count
argument_list|()
operator|-
literal|1
condition|)
name|end
operator|=
name|m_colorNames
operator|.
name|count
argument_list|()
operator|-
literal|1
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
name|start
init|;
name|i
operator|<=
name|end
condition|;
operator|++
name|i
operator|,
name|y
operator|+=
name|m_height
control|)
block|{
name|p
operator|.
name|setBrush
argument_list|(
name|Qt
operator|::
name|NoBrush
argument_list|)
expr_stmt|;
name|p
operator|.
name|setPen
argument_list|(
name|Qt
operator|::
name|black
argument_list|)
expr_stmt|;
if|if
condition|(
name|i
operator|==
name|m_highlight
condition|)
block|{
name|p
operator|.
name|fillRect
argument_list|(
literal|0
argument_list|,
name|y
argument_list|,
name|width
argument_list|()
argument_list|,
name|m_height
argument_list|,
name|QColor
argument_list|(
literal|0
argument_list|,
literal|64
argument_list|,
literal|128
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
block|}
if|if
condition|(
name|i
operator|==
name|m_selected
condition|)
block|{
name|p
operator|.
name|fillRect
argument_list|(
literal|0
argument_list|,
name|y
argument_list|,
name|width
argument_list|()
argument_list|,
name|m_height
argument_list|,
name|QColor
argument_list|(
literal|0
argument_list|,
literal|128
argument_list|,
literal|240
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
block|}
name|p
operator|.
name|drawText
argument_list|(
name|m_height
operator|+
literal|2
argument_list|,
name|y
argument_list|,
name|width
argument_list|()
argument_list|,
name|m_height
argument_list|,
name|Qt
operator|::
name|AlignVCenter
argument_list|,
name|m_colorNames
index|[
name|i
index|]
argument_list|)
expr_stmt|;
name|p
operator|.
name|setPen
argument_list|(
name|Qt
operator|::
name|NoPen
argument_list|)
expr_stmt|;
name|p
operator|.
name|setBrush
argument_list|(
name|m_firstColor
index|[
name|i
index|]
argument_list|)
expr_stmt|;
name|p
operator|.
name|drawRect
argument_list|(
literal|1
argument_list|,
name|y
operator|+
literal|1
argument_list|,
name|m_height
operator|-
literal|2
argument_list|,
name|m_height
operator|-
literal|2
argument_list|)
expr_stmt|;
name|p
operator|.
name|setBrush
argument_list|(
name|m_secondColor
index|[
name|i
index|]
argument_list|)
expr_stmt|;
name|p
operator|.
name|drawRect
argument_list|(
literal|5
argument_list|,
name|y
operator|+
literal|5
argument_list|,
name|m_height
operator|-
literal|11
argument_list|,
name|m_height
operator|-
literal|11
argument_list|)
expr_stmt|;
block|}
name|p
operator|.
name|end
argument_list|()
expr_stmt|;
block|}
DECL|function|keyReleaseEvent
name|void
name|keyReleaseEvent
parameter_list|(
name|QKeyEvent
modifier|*
name|event
parameter_list|)
block|{
if|if
condition|(
name|event
operator|->
name|key
argument_list|()
operator|==
name|Qt
operator|::
name|Key_Down
condition|)
block|{
name|m_offset
operator|+=
literal|20
expr_stmt|;
name|event
operator|->
name|accept
argument_list|()
expr_stmt|;
name|update
argument_list|()
expr_stmt|;
return|return;
block|}
if|if
condition|(
name|event
operator|->
name|key
argument_list|()
operator|==
name|Qt
operator|::
name|Key_Up
condition|)
block|{
name|m_offset
operator|-=
literal|20
expr_stmt|;
name|event
operator|->
name|accept
argument_list|()
expr_stmt|;
name|update
argument_list|()
expr_stmt|;
return|return;
block|}
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
name|Flickable
operator|::
name|handleMousePress
argument_list|(
name|event
argument_list|)
expr_stmt|;
if|if
condition|(
name|event
operator|->
name|isAccepted
argument_list|()
condition|)
return|return;
if|if
condition|(
name|event
operator|->
name|button
argument_list|()
operator|==
name|Qt
operator|::
name|LeftButton
condition|)
block|{
name|int
name|y
init|=
name|event
operator|->
name|pos
argument_list|()
operator|.
name|y
argument_list|()
operator|+
name|m_offset
decl_stmt|;
name|int
name|i
init|=
name|y
operator|/
name|m_height
decl_stmt|;
if|if
condition|(
name|i
operator|!=
name|m_highlight
condition|)
block|{
name|m_highlight
operator|=
name|i
expr_stmt|;
name|m_selected
operator|=
operator|-
literal|1
expr_stmt|;
name|update
argument_list|()
expr_stmt|;
block|}
name|event
operator|->
name|accept
argument_list|()
expr_stmt|;
block|}
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
name|Flickable
operator|::
name|handleMouseMove
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
name|Flickable
operator|::
name|handleMouseRelease
argument_list|(
name|event
argument_list|)
expr_stmt|;
if|if
condition|(
name|event
operator|->
name|isAccepted
argument_list|()
condition|)
return|return;
if|if
condition|(
name|event
operator|->
name|button
argument_list|()
operator|==
name|Qt
operator|::
name|LeftButton
condition|)
block|{
name|m_selected
operator|=
name|m_highlight
expr_stmt|;
name|event
operator|->
name|accept
argument_list|()
expr_stmt|;
name|update
argument_list|()
expr_stmt|;
block|}
block|}
private|private:
DECL|member|m_offset
name|int
name|m_offset
decl_stmt|;
DECL|member|m_height
name|int
name|m_height
decl_stmt|;
DECL|member|m_highlight
name|int
name|m_highlight
decl_stmt|;
DECL|member|m_selected
name|int
name|m_selected
decl_stmt|;
DECL|member|m_colorNames
name|QStringList
name|m_colorNames
decl_stmt|;
DECL|member|m_firstColor
name|QList
argument_list|<
name|QColor
argument_list|>
name|m_firstColor
decl_stmt|;
DECL|member|m_secondColor
name|QList
argument_list|<
name|QColor
argument_list|>
name|m_secondColor
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
name|ColorList
name|list
decl_stmt|;
name|list
operator|.
name|setWindowTitle
argument_list|(
literal|"Kinetic Scrolling"
argument_list|)
expr_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_SYMBIAN
argument_list|)
operator|||
name|defined
argument_list|(
name|Q_OS_WINCE_WM
argument_list|)
name|list
operator|.
name|showMaximized
argument_list|()
expr_stmt|;
else|#
directive|else
name|list
operator|.
name|resize
argument_list|(
literal|320
argument_list|,
literal|320
argument_list|)
expr_stmt|;
name|list
operator|.
name|show
argument_list|()
expr_stmt|;
endif|#
directive|endif
return|return
name|app
operator|.
name|exec
argument_list|()
return|;
block|}
end_function
end_unit
