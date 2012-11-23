begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the demonstration applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|PATHSTROKE_H
end_ifndef
begin_define
DECL|macro|PATHSTROKE_H
define|#
directive|define
name|PATHSTROKE_H
end_define
begin_include
include|#
directive|include
file|"arthurwidgets.h"
end_include
begin_include
include|#
directive|include
file|<QtWidgets>
end_include
begin_decl_stmt
name|class
name|PathStrokeRenderer
range|:
name|public
name|ArthurFrame
block|{
name|Q_OBJECT
name|Q_PROPERTY
argument_list|(
argument|bool animation READ animation WRITE setAnimation
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|qreal penWidth READ realPenWidth WRITE setRealPenWidth
argument_list|)
name|public
operator|:
expr|enum
name|PathMode
block|{
name|CurveMode
block|,
name|LineMode
block|}
block|;
name|explicit
name|PathStrokeRenderer
argument_list|(
argument|QWidget *parent
argument_list|,
argument|bool smallScreen = false
argument_list|)
block|;
name|void
name|paint
argument_list|(
name|QPainter
operator|*
argument_list|)
block|;
name|void
name|mousePressEvent
argument_list|(
name|QMouseEvent
operator|*
name|e
argument_list|)
block|;
name|void
name|mouseMoveEvent
argument_list|(
name|QMouseEvent
operator|*
name|e
argument_list|)
block|;
name|void
name|mouseReleaseEvent
argument_list|(
name|QMouseEvent
operator|*
name|e
argument_list|)
block|;
name|void
name|timerEvent
argument_list|(
name|QTimerEvent
operator|*
name|e
argument_list|)
block|;
name|bool
name|event
argument_list|(
name|QEvent
operator|*
name|e
argument_list|)
block|;
name|QSize
name|sizeHint
argument_list|()
specifier|const
block|{
return|return
name|QSize
argument_list|(
literal|500
argument_list|,
literal|500
argument_list|)
return|;
block|}
name|bool
name|animation
argument_list|()
specifier|const
block|{
return|return
name|m_timer
operator|.
name|isActive
argument_list|()
return|;
block|}
name|qreal
name|realPenWidth
argument_list|()
specifier|const
block|{
return|return
name|m_penWidth
return|;
block|}
name|void
name|setRealPenWidth
argument_list|(
argument|qreal penWidth
argument_list|)
block|{
name|m_penWidth
operator|=
name|penWidth
block|;
name|update
argument_list|()
block|; }
name|signals
operator|:
name|void
name|clicked
argument_list|()
block|;
name|public
name|slots
operator|:
name|void
name|setPenWidth
argument_list|(
argument|int penWidth
argument_list|)
block|{
name|m_penWidth
operator|=
name|penWidth
operator|/
literal|10.0
block|;
name|update
argument_list|()
block|; }
name|void
name|setAnimation
argument_list|(
argument|bool animation
argument_list|)
block|;
name|void
name|setFlatCap
argument_list|()
block|{
name|m_capStyle
operator|=
name|Qt
operator|::
name|FlatCap
block|;
name|update
argument_list|()
block|; }
name|void
name|setSquareCap
argument_list|()
block|{
name|m_capStyle
operator|=
name|Qt
operator|::
name|SquareCap
block|;
name|update
argument_list|()
block|; }
name|void
name|setRoundCap
argument_list|()
block|{
name|m_capStyle
operator|=
name|Qt
operator|::
name|RoundCap
block|;
name|update
argument_list|()
block|; }
name|void
name|setBevelJoin
argument_list|()
block|{
name|m_joinStyle
operator|=
name|Qt
operator|::
name|BevelJoin
block|;
name|update
argument_list|()
block|; }
name|void
name|setMiterJoin
argument_list|()
block|{
name|m_joinStyle
operator|=
name|Qt
operator|::
name|MiterJoin
block|;
name|update
argument_list|()
block|; }
name|void
name|setRoundJoin
argument_list|()
block|{
name|m_joinStyle
operator|=
name|Qt
operator|::
name|RoundJoin
block|;
name|update
argument_list|()
block|; }
name|void
name|setCurveMode
argument_list|()
block|{
name|m_pathMode
operator|=
name|CurveMode
block|;
name|update
argument_list|()
block|; }
name|void
name|setLineMode
argument_list|()
block|{
name|m_pathMode
operator|=
name|LineMode
block|;
name|update
argument_list|()
block|; }
name|void
name|setSolidLine
argument_list|()
block|{
name|m_penStyle
operator|=
name|Qt
operator|::
name|SolidLine
block|;
name|update
argument_list|()
block|; }
name|void
name|setDashLine
argument_list|()
block|{
name|m_penStyle
operator|=
name|Qt
operator|::
name|DashLine
block|;
name|update
argument_list|()
block|; }
name|void
name|setDotLine
argument_list|()
block|{
name|m_penStyle
operator|=
name|Qt
operator|::
name|DotLine
block|;
name|update
argument_list|()
block|; }
name|void
name|setDashDotLine
argument_list|()
block|{
name|m_penStyle
operator|=
name|Qt
operator|::
name|DashDotLine
block|;
name|update
argument_list|()
block|; }
name|void
name|setDashDotDotLine
argument_list|()
block|{
name|m_penStyle
operator|=
name|Qt
operator|::
name|DashDotDotLine
block|;
name|update
argument_list|()
block|; }
name|void
name|setCustomDashLine
argument_list|()
block|{
name|m_penStyle
operator|=
name|Qt
operator|::
name|NoPen
block|;
name|update
argument_list|()
block|; }
name|private
operator|:
name|void
name|initializePoints
argument_list|()
block|;
name|void
name|updatePoints
argument_list|()
block|;
name|QBasicTimer
name|m_timer
block|;
name|PathMode
name|m_pathMode
block|;
name|bool
name|m_wasAnimated
block|;
name|qreal
name|m_penWidth
block|;
name|int
name|m_pointCount
block|;
name|int
name|m_pointSize
block|;
name|int
name|m_activePoint
block|;
name|QVector
operator|<
name|QPointF
operator|>
name|m_points
block|;
name|QVector
operator|<
name|QPointF
operator|>
name|m_vectors
block|;
name|Qt
operator|::
name|PenJoinStyle
name|m_joinStyle
block|;
name|Qt
operator|::
name|PenCapStyle
name|m_capStyle
block|;
name|Qt
operator|::
name|PenStyle
name|m_penStyle
block|;
name|bool
name|m_smallScreen
block|;
name|QPoint
name|m_mousePress
block|;
name|bool
name|m_mouseDrag
block|;
name|QHash
operator|<
name|int
block|,
name|int
operator|>
name|m_fingerPointMapping
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|PathStrokeControls
range|:
name|public
name|QWidget
block|{
name|Q_OBJECT
name|public
operator|:
name|PathStrokeControls
argument_list|(
argument|QWidget* parent
argument_list|,
argument|PathStrokeRenderer* renderer
argument_list|,
argument|bool smallScreen
argument_list|)
block|;
name|signals
operator|:
name|void
name|okPressed
argument_list|()
block|;
name|void
name|quitPressed
argument_list|()
block|;
name|private
operator|:
name|PathStrokeRenderer
operator|*
name|m_renderer
block|;
name|QGroupBox
operator|*
name|m_capGroup
block|;
name|QGroupBox
operator|*
name|m_joinGroup
block|;
name|QGroupBox
operator|*
name|m_styleGroup
block|;
name|QGroupBox
operator|*
name|m_pathModeGroup
block|;
name|void
name|createCommonControls
argument_list|(
name|QWidget
operator|*
name|parent
argument_list|)
block|;
name|void
name|layoutForDesktop
argument_list|()
block|;
name|void
name|layoutForSmallScreens
argument_list|()
block|;
name|private
name|slots
operator|:
name|void
name|emitQuitSignal
argument_list|()
block|;
name|void
name|emitOkSignal
argument_list|()
block|;  }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|PathStrokeWidget
range|:
name|public
name|QWidget
block|{
name|Q_OBJECT
name|public
operator|:
name|PathStrokeWidget
argument_list|(
argument|bool smallScreen
argument_list|)
block|;
name|void
name|setStyle
argument_list|(
name|QStyle
operator|*
name|style
argument_list|)
block|;
name|private
operator|:
name|PathStrokeRenderer
operator|*
name|m_renderer
block|;
name|PathStrokeControls
operator|*
name|m_controls
block|;
name|private
name|slots
operator|:
name|void
name|showControls
argument_list|()
block|;
name|void
name|hideControls
argument_list|()
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// PATHSTROKE_H
end_comment
end_unit
