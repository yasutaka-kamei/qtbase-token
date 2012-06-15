begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtGui>
end_include
begin_include
include|#
directive|include
file|"rasterwindow.h"
end_include
begin_comment
comment|//! [5]
end_comment
begin_class
DECL|class|AnalogClockWindow
class|class
name|AnalogClockWindow
super|:
specifier|public
name|RasterWindow
block|{
public|public:
name|AnalogClockWindow
parameter_list|()
constructor_decl|;
protected|protected:
name|void
name|timerEvent
parameter_list|(
name|QTimerEvent
modifier|*
parameter_list|)
function_decl|;
name|void
name|render
parameter_list|(
name|QPainter
modifier|*
name|p
parameter_list|)
function_decl|;
private|private:
DECL|member|m_timerId
name|int
name|m_timerId
decl_stmt|;
block|}
class|;
end_class
begin_comment
comment|//! [5]
end_comment
begin_comment
comment|//! [6]
end_comment
begin_constructor
DECL|function|AnalogClockWindow
name|AnalogClockWindow
operator|::
name|AnalogClockWindow
parameter_list|()
block|{
name|setWindowTitle
argument_list|(
literal|"Analog Clock"
argument_list|)
expr_stmt|;
name|resize
argument_list|(
literal|200
argument_list|,
literal|200
argument_list|)
expr_stmt|;
name|m_timerId
operator|=
name|startTimer
argument_list|(
literal|1000
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|//! [6]
end_comment
begin_comment
comment|//! [7]
end_comment
begin_function
DECL|function|timerEvent
name|void
name|AnalogClockWindow
operator|::
name|timerEvent
parameter_list|(
name|QTimerEvent
modifier|*
name|event
parameter_list|)
block|{
if|if
condition|(
name|event
operator|->
name|timerId
argument_list|()
operator|==
name|m_timerId
condition|)
name|renderLater
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [7]
end_comment
begin_comment
comment|//! [1] //! [14]
end_comment
begin_function
DECL|function|render
name|void
name|AnalogClockWindow
operator|::
name|render
parameter_list|(
name|QPainter
modifier|*
name|p
parameter_list|)
block|{
comment|//! [14]
comment|//! [8]
specifier|static
specifier|const
name|QPoint
name|hourHand
index|[
literal|3
index|]
init|=
block|{
name|QPoint
argument_list|(
literal|7
argument_list|,
literal|8
argument_list|)
block|,
name|QPoint
argument_list|(
operator|-
literal|7
argument_list|,
literal|8
argument_list|)
block|,
name|QPoint
argument_list|(
literal|0
argument_list|,
argument|-
literal|40
argument_list|)
block|}
decl_stmt|;
specifier|static
specifier|const
name|QPoint
name|minuteHand
index|[
literal|3
index|]
init|=
block|{
name|QPoint
argument_list|(
literal|7
argument_list|,
literal|8
argument_list|)
block|,
name|QPoint
argument_list|(
operator|-
literal|7
argument_list|,
literal|8
argument_list|)
block|,
name|QPoint
argument_list|(
literal|0
argument_list|,
argument|-
literal|70
argument_list|)
block|}
decl_stmt|;
name|QColor
name|hourColor
argument_list|(
literal|127
argument_list|,
literal|0
argument_list|,
literal|127
argument_list|)
decl_stmt|;
name|QColor
name|minuteColor
argument_list|(
literal|0
argument_list|,
literal|127
argument_list|,
literal|127
argument_list|,
literal|191
argument_list|)
decl_stmt|;
comment|//! [8]
comment|//! [9]
name|p
operator|->
name|setRenderHint
argument_list|(
name|QPainter
operator|::
name|Antialiasing
argument_list|)
expr_stmt|;
comment|//! [9] //! [10]
name|p
operator|->
name|translate
argument_list|(
name|width
argument_list|()
operator|/
literal|2
argument_list|,
name|height
argument_list|()
operator|/
literal|2
argument_list|)
expr_stmt|;
name|int
name|side
init|=
name|qMin
argument_list|(
name|width
argument_list|()
argument_list|,
name|height
argument_list|()
argument_list|)
decl_stmt|;
name|p
operator|->
name|scale
argument_list|(
name|side
operator|/
literal|200.0
argument_list|,
name|side
operator|/
literal|200.0
argument_list|)
expr_stmt|;
comment|//! [1] //! [10]
comment|//! [11]
name|p
operator|->
name|setPen
argument_list|(
name|Qt
operator|::
name|NoPen
argument_list|)
expr_stmt|;
name|p
operator|->
name|setBrush
argument_list|(
name|hourColor
argument_list|)
expr_stmt|;
comment|//! [11]
comment|//! [2]
name|QTime
name|time
init|=
name|QTime
operator|::
name|currentTime
argument_list|()
decl_stmt|;
name|p
operator|->
name|save
argument_list|()
expr_stmt|;
name|p
operator|->
name|rotate
argument_list|(
literal|30.0
operator|*
operator|(
operator|(
name|time
operator|.
name|hour
argument_list|()
operator|+
name|time
operator|.
name|minute
argument_list|()
operator|/
literal|60.0
operator|)
operator|)
argument_list|)
expr_stmt|;
name|p
operator|->
name|drawConvexPolygon
argument_list|(
name|hourHand
argument_list|,
literal|3
argument_list|)
expr_stmt|;
name|p
operator|->
name|restore
argument_list|()
expr_stmt|;
comment|//! [2]
comment|//! [12]
name|p
operator|->
name|setPen
argument_list|(
name|hourColor
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
literal|12
condition|;
operator|++
name|i
control|)
block|{
name|p
operator|->
name|drawLine
argument_list|(
literal|88
argument_list|,
literal|0
argument_list|,
literal|96
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|p
operator|->
name|rotate
argument_list|(
literal|30.0
argument_list|)
expr_stmt|;
block|}
comment|//! [12] //! [13]
name|p
operator|->
name|setPen
argument_list|(
name|Qt
operator|::
name|NoPen
argument_list|)
expr_stmt|;
name|p
operator|->
name|setBrush
argument_list|(
name|minuteColor
argument_list|)
expr_stmt|;
comment|//! [13]
comment|//! [3]
name|p
operator|->
name|save
argument_list|()
expr_stmt|;
name|p
operator|->
name|rotate
argument_list|(
literal|6.0
operator|*
operator|(
name|time
operator|.
name|minute
argument_list|()
operator|+
name|time
operator|.
name|second
argument_list|()
operator|/
literal|60.0
operator|)
argument_list|)
expr_stmt|;
name|p
operator|->
name|drawConvexPolygon
argument_list|(
name|minuteHand
argument_list|,
literal|3
argument_list|)
expr_stmt|;
name|p
operator|->
name|restore
argument_list|()
expr_stmt|;
comment|//! [3]
comment|//! [4]
name|p
operator|->
name|setPen
argument_list|(
name|minuteColor
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|j
init|=
literal|0
init|;
name|j
operator|<
literal|60
condition|;
operator|++
name|j
control|)
block|{
if|if
condition|(
operator|(
name|j
operator|%
literal|5
operator|)
operator|!=
literal|0
condition|)
name|p
operator|->
name|drawLine
argument_list|(
literal|92
argument_list|,
literal|0
argument_list|,
literal|96
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|p
operator|->
name|rotate
argument_list|(
literal|6.0
argument_list|)
expr_stmt|;
block|}
comment|//! [4]
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
name|QGuiApplication
name|app
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
decl_stmt|;
name|AnalogClockWindow
name|clock
decl_stmt|;
name|clock
operator|.
name|show
argument_list|()
expr_stmt|;
name|app
operator|.
name|exec
argument_list|()
expr_stmt|;
block|}
end_function
end_unit
